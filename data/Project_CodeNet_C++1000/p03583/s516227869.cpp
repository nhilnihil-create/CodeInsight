#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    ll N;
    cin>>N;
    ll w,ww,www;
    for(ll n=1;n<=3500;n++){
        for(ll h=1;h<=3500;h++){
            ll z=4*n*h-n*N-h*N;
            if(z<=0) continue;
            ll a=N*h*n;
            if(a%z==0){
                w=a/z;
                ww=h;
                www=n;
                break;
            }
        }
    }
    cout<<w<<' '<<ww<<' '<<www<<endl;
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
/*
V,P(大文字)使用不可
乗算の際にオーバーフローに注意せよ！(適切にmodをとれ)
制約をよく読め！
(全探索できるなら全探索しろ)
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'\n'
*/