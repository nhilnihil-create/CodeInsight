#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    double t,a;cin>>t>>a;
    vector<double> h(n);
    rep(i,n) cin>>h[i];
    int res=-1;double tmp=10000;
    rep(i,n){
        double now=t-h[i]*0.006;
        if(chmin(tmp,abs(a-now)))res=i;
    }
    cout<<res+1<<endl;
}