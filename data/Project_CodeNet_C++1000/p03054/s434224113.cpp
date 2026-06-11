#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<char,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    ll N;
    cin >> N;
    ll sr;
    cin >> sr;sr--;
    ll sc;
    cin >> sc;sc--;
    string S;
    cin >> S;
    string T;
    cin >> T;
    ll sr1=sr,sr2=sr,sr3=sr;
    ll sc1=sc,sc2=sc,sc3=sc;

    for(ll i=0;i<N;i++){
        if(S[i]=='U')sr--;
        if(sr<0){cout<<"NO"<<endl;return 0;}
        if(T[i]=='D'&&sr<H-1)sr++;
    ;}
    for(ll i=0;i<N;i++){
        if(S[i]=='D')sr1++;
        if(sr1>=H){cout<<"NO"<<endl;return 0;}
        if(T[i]=='U'&&sr1>0)sr1--;
    ;}
    for(ll i=0;i<N;i++){
        if(S[i]=='L')sc2--;
        if(sc2<0){cout<<"NO"<<endl;return 0;}
        if(T[i]=='R'&&sc2<W-1)sc2++;
    ;}
    for(ll i=0;i<N;i++){
        if(S[i]=='R')sc3++;
        if(sc3>=W){cout<<"NO"<<endl;return 0;}
        if(T[i]=='L'&&sc3>0)sc3--;
    ;}
    cout<<"YES"<<endl;




    return 0;
}
