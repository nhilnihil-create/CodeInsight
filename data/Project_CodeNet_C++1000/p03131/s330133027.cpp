//例3がオーバーフローする以外できてる

// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
//#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,n,f=0,mini=INF;
    ll sum=0,maxi=0;
    string str,sub;
    ll h,w;
    ll m,k,d;
    ll x;
    cin>>k>>a>>b;
    if(a+1>=b) cout<<k+1<<endl;
    else{
        k=k-a+1;
        sum=a;
        if(k%2) sum++;
        sum+=(b-a)*(k/2);
        //if(k==1) sum++;
        cout<<sum<<endl;
    }
    return 0;
}
