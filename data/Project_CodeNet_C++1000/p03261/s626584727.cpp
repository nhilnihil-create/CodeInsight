#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;

int main(){
    int n; cin >> n;
    vector<string> w(n),W(n);
    rep(i,n) {
        cin >> w[i];
        W[i] = w[i];
    }
    sort(W.begin(),W.end());
    rep(i,n-1){
        if(W[i+1] == W[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 0;i < n - 1;i++){
        string a = w[i],b = w[i+1];
        int as = a.size(), bs = b.size();
        if(a[as - 1] != b[0]) {
            cout << "No" << endl; 
            return 0;
        }
    } 
    cout << "Yes" << endl;
}