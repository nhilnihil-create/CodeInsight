#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
string s;
cin>>s;
int n = s.size();
bool ok=false;

reps(i,n,1){
    rep(j,n-i){
        string s1=s.substr(0,i);
        string s2=s.substr(i+j,n-i+j);
        if(s1+s2=="keyence"){
            ok=true;
        }
    }
}
if(ok){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}
return 0;
}