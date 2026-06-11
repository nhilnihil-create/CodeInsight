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

    ll a,b,c,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    ll h,w;
    cin>>w>>str;
    //string stra[h];
    for(ll i=1;i<w;i++){
        set<string> bs;
        set<string> as;
        rep(j,i){
            bs.insert(str.substr(j,1));
                        //cout<<str.substr(j,1);
        }
        for(ll j=i;j<w;j++){
            as.insert(str.substr(j,1));
            //cout<<str.substr(j,1);
        }
        for(auto itr=as.begin();itr!=as.end();++itr){
            if(bs.find(*itr)!=bs.end()) f++;
            //cout<<*itr;
        }
        maxi=max(f,maxi);
        f=0;
        //cout<<"aaa";
    }
    cout<<maxi<<endl;


    //cout<<sum<<endl;
    return 0;
}
