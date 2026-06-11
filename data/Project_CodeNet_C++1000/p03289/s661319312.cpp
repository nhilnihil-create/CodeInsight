#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
#define Sort(v) sort(all(v))
#define Reverse(v) reverse(all(v))
#define Rsort(v) sort(all(v),greater)
#define pub(v) push_back(v)
#define pob(v) pop_back(v)
typedef long long ll;
typedef vector<ll> vel;
typedef vector<vector<ll>> vel2d;
typedef string str;
typedef pair<ll,ll> pal;
typedef vector<str> ves;
typedef vector<char> vech;

int main(){
    str S;cin>>S;
    if(S[0]!='A'){cout<<"WA"<<endl;return 0;}
    else{S[0]='a';}
    ll m=S.size();
    ll cnt=0;
    for(ll i=2;i<=m-2;i++){
        if(S[i]=='C'){S[i]='c';cnt++;}
        if(i==m-2&&cnt>=2){cout<<"WA"<<endl;return 0;}
    }
    if(cnt==0){cout<<"WA"<<endl;return 0;}
    bool flag=false;
    rep0(i,m){
        if(0<=(ll)(S[i]-'a')&&(ll)(S[i]-'a')<26){
            flag=true;
        }
        else{flag=false;break;}
    }
    if(flag){cout<<"AC"<<endl;}
    else{cout<<"WA"<<endl;}
}
      