#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    ll res1=a*x+b*y;
    ll res2=min(x,y)*c*2+((x>y)? (x-y)*a:(y-x)*b);
    ll res3=max(x,y)*c*2;
    ll res=min(res1,min(res3,res2));
    cout<<res<<endl;
}