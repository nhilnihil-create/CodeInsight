#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;string s;cin>>s;
    vector<int> a(n,0),b(n,0);
    rep(i,n){
        if(s[i]=='W')a[i]++;
        else b[i]++;
    }
    reverse(b.begin(),b.end());
    rep(i,n-1){
        a[i+1]+=a[i];
        b[i+1]+=b[i];
    }
    reverse(b.begin(),b.end());
    int res=1e6;
    rep(i,n)chmin(res,(a[i]+b[i]-1));
    cout<<res<<endl;
}