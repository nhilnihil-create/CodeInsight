// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n;
    ll a,b;
    ll k,t;
    string str;
    ll h,w;
    char c,ko;
    cin>>n;
    ll sum=0;
    ll i=335;
    while(i<=n){
         ll m=i;
        a=0;b=0;k=0;
        while(m>0){
            
            if(m%10==3) a++;
            else if(m%10==5) b++;
            else if(m%10==7) k++;
            else {
                a=0;
                break;
            }
                    m/=10;
        }
        if(a&&b&&k) sum++;
       // cout<<"a"<<endl;
        if(i%10==3||i%10==5){
            i+=2;
        }else{
            i+=6;
        }
       
        }
cout<<sum<<endl;
    return 0;
}
