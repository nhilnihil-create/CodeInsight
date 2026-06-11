#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<cmath>
#include<stack>
#include<string.h>
#include <iomanip>
#define rep(i,n) for(int i = 0;i<n;i++)
#define _GLIBCXX_DEBUG
using ll = long long; 
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n,m;
    cin >> n >> m;
    vector<int>p(m),y(m);
    rep(i,m) {
        cin >> p[i] >> y[i];
        p[i]--;
    }    
    vector<vector<int>>val(n);
    rep(i,m) {
        val[p[i]].push_back(y[i]);
    }
    rep(i,n) {
        sort(val[i].begin(),val[i].end());
    }
    rep(i,m) {
        printf("%06d",p[i]+1);
        int id = lower_bound(val[p[i]].begin(),val[p[i]].end(),y[i])-val[p[i]].begin();
        printf("%06d\n",id+1);
    }
}