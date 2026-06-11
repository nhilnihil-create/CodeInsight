// lcmとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
using namespace std;
bool my_compare(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        // どちらも同じ
        return true;
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str,sub;
    ll h,w;
    string str1;
    cin>>h>>w;
    string s[h];
    rep(i,h) cin>>s[i];
    //f=1;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'){
                f=0;
                if(i!=0) if(s[i-1][j]=='#') f=1;
                if(j!=0) if(s[i][j-1]=='#') f=1;
                if(i+1!=h) if(s[i+1][j]=='#') f=1;
                if(j+1!=w) if(s[i][j+1]=='#') f=1;
                if(f==0){
                    No;
                    return 0;
                }
            }
        }
    }

    Yes;

    return 0;
}
