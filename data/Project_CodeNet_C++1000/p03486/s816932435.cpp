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
    double sum=0,maxi=0;
    string str,sub;
    ll h,w;
    ll m,k;
    cin>>str>>sub;
    char tmp;
            rep(j,100){

    rep(i,100){
        if(i<str.length()-1&&str[i]>str[i+1]){
            tmp=str[i];
            str[i]=str[i+1];
            str[i+1]=tmp;
        }
        if(i<sub.length()-1&&sub[i]<sub[i+1]){
            tmp=sub[i];
            sub[i]=sub[i+1];
            sub[i+1]=tmp;
        }
        }
    }
    //cout<<str<<endl<<sub<<endl;
    if(str<sub) Yes;
    else No;
    return 0;
}
