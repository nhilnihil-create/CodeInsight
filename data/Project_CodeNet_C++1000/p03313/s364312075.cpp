#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
//#define int long long
#define ld long double
#define vi vector<ll>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define il pair<ll,ll>
#define vv vector
//#define endl '\n'
using namespace std;
const int MAXN = 700 + 5;
 
set<ii> s[(1<<18)];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int xx = n;
    n = (1<<n);
    int arr[n];
    FOR(i,n)cin >> arr[i];
    FOR(i,n)s[i].insert({arr[i],i});
    FOR(i,n){
    	FOR(j,xx){
    		int v = i|(1<<j);
    		if(v != i){
    			for(auto e: s[i])s[v].insert(e);
    			while(s[v].size() > 2)s[v].erase(s[v].begin());
    		}
    	}
    }
    int mx = 0;
    FOR(i,n){
    	int sum = 0;
    	for(auto e :s[i])sum += e.ff;
    	mx = max(mx,sum);
    	if(i > 0)cout << mx << endl;
    }
 
    return 0;
}