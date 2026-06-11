#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;


int main(){
    map<string, vector<P> > mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        int p;
        cin>>s>>p;
        mp[s].push_back(P(-p,i+1));
    }
    for(auto vp:mp){
        sort(vp.second.begin(), vp.second.end());
        for(auto p:vp.second){
            cout<<p.second<<endl;
        }
    }
}