#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s,t;

int main(){
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<char>());
    if(s<t) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}
