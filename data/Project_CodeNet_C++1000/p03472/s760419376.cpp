#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
typedef pair<ll, ll> P;
const ll INF=1LL<<60;
ll gcd(ll x,ll y){return y? gcd(y,x%y) :x;}

int main(){
    int n;
    ll h;
    cin>>n>>h;
    priority_queue<ll> a,b;
    rep(i,n){
        ll x,y;
        cin>>x>>y;
        a.push(x);
        b.push(y);
    }
    ll cnt=0;
    while(h){
        cnt++;
        //cout<<cnt<<" "<<h<<" ";
        ll x,y;
        x=a.top();a.pop();
        if(b.empty())y=0;
        else {y=b.top();b.pop();}
        //cout<<x<<" "<<y<<endl;
        if(x>=y){
            ll kazu=h/x;
            if(h%x!=0)kazu++;
            cnt+=kazu-1;
            h=0;
            a.push(x);
            b.push(y);
            //cout<<"a";
        }else {
            h-=y;
            a.push(x);
            //cout<<"b";
        }
        if(h<=0)break;
    }
    cout<<cnt<<endl;
}