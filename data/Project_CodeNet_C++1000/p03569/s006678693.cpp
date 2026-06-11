#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



int main(){
    string s;
    cin >> s;
    ll N=s.size();
    vector<ll> noX(0);
    vector<ll> rnoX(0);
    for(ll i=0;i<N;i++){
        if(s[i]!='x'){
            noX.emplace_back(s[i]);
            rnoX.emplace_back(s[i]);
        }
    ;}
    reverse(rnoX.begin(), rnoX.end());
    bool check=1;
    ll M=noX.size();
    for(ll i=0;i<M;i++){
        if(noX[i]!=rnoX[i])check=0;
    ;}
    if(!check){cout<<-1<<endl;return 0;}
    vector<ll> countX(0);
    vector<ll> rcountX(0);
    ll counter=0;
    for(ll i=0;i<N;i++){
        if(s[i]=='x'){counter++;}
        else {
            countX.emplace_back(counter);
            rcountX.emplace_back(counter);
            counter=0;}
    ;}
    countX.emplace_back(counter);
    rcountX.emplace_back(counter);
    reverse(rcountX.begin(), rcountX.end());
    counter=0;
    for(ll i=0;i<countX.size();i++){
        counter+=abs(countX[i]-rcountX[i])
    ;}
    cout<<counter/2<<endl;



    return 0;
}
