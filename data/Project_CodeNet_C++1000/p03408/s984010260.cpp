#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

map<string, int>memo;

int main() {
    int n;cin>>n;
    rep(i,n){
        string s;cin>>s;
        memo[s]+=1;
    }
    int m;cin>>m;
    rep(i,m){
        string t;cin>>t;
        memo[t]-=1;
    }
    int maxv = 0;
    for(const auto& x:memo){
        int v = x.second;
        if(v > maxv)maxv=v;
    }
    cout<<maxv<<endl;
	return 0;
}