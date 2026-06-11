#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll h,w;cin>>h>>w;
    if(h>w)swap(h,w);
    ll res=(h-2)*(w-2);
    if(h==1&&w==1){
        cout<<1<<endl;
        return 0;
    }else if(h==1){
        cout<<w-2<<endl;
        return 0;
    }
    cout<<res<<endl;
}