// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
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

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    vector<ll> v(5);
    cin>>str;
    if(str[0]!='A') f=1;
    if(str[1]<='A') f=1; 
    if(str[1]<='Z'&&str[1]>='A') f=1; 
    //cout<<f;
    REP(i,2,str.length()-1){
        if(str[i]=='C') sum++;
        else{
            if(str[i]<='A') f=1; 
        }
    }
    //cout<<f;
    if(str[str.length()-1]<='Z'&&str[str.length()-1]>='A') f=1; 
    //if(str[str.length()-2]<='A') f=1; 
    //if(str[str.length()-1]<='A') f=1; 

    if(sum!=1) f=1;
    if(f==1) cout<<"WA"<<endl;
    else cout<<"AC"<<endl;

    return 0;
}
