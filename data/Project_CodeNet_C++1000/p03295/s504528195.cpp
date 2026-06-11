#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ll long long
#define ln cout<<'\n'
#define Z class
typedef pair<int,int> P;

#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main(){

    // input 
    ll n,m;
    cin >> n >> m;
    P a[m];   // 要望：pair <終わり、始点＞
    rep(i,m) cin >> a[i].S >> a[i].F;  // pair <終わり、始点＞
    
    // 終わりが早い順にソート
    sort(a,a+m);
    // pari <始点、終わり＞　に戻す
    rep(i,m) swap(a[i].F,a[i].S);

    int ans=0,x=0;
    rep(i,m) {
        if(a[i].F<x) continue;
        else {
             x=a[i].S;
             ans++;
        }
    }

    // output 
    pr(ans);


    
    return 0;

}