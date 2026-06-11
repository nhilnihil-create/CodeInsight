#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<char,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



int main(){
    ll N;
    cin >> N;
    vector<ll> a(N+1,0);
    for(ll i=0;i<N;i++){
        cin>>a[i+1]
    ;}
    deque<ll> deq;
    for(ll i=1;i<=N;i++){
        ll k;
        for(ll j=a.size()-1;j>=1;j--){
            if(a[j]==j){deq.emplace_front(j);k=j;break;}
            if(j==1){cout<<-1<<endl;return 0;}
        ;}
        vector<ll> b(a.size()-1,0);
        for(ll i=1;i<=k-1;i++){
            b[i]=a[i];
        ;}
        for(ll i=k;i<=a.size()-2;i++){
            b[i]=a[i+1];
        ;}
        a.pop_back();
        for(ll i=1;i<=a.size()-1;i++){
            a[i]=b[i];
        ;}
    ;}
    for(ll i=0;i<N;i++){
        cout<<deq.front()<<endl;
        deq.pop_front();
    ;}
return 0;
}
