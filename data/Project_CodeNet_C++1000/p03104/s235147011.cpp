/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass the Test!
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;
ll N;

int main(){
    ll A;
    cin >> A;
    ll B;
    cin >> B;
    //Acount[i]はA以下で(?&(1<<i))となる?の個数の偶奇
    vector<ll> Acount(50,0LL);
    vector<ll> Bcount(50,0LL);
    if(A>0)
    for(ll i=0;i<50;i++){ll a;
        if(i==0){
            a=A%4;
            if(a==0||a==1)Acount[0]=0LL;
            else Acount[0]=1LL;
            continue;
        }
        else {a=(ll)A%(1LL<<(i+1));
        Acount[i]=(ll)max(0LL,a-(1LL<<i))%2;}
    ;}
    for(ll i=0;i<50;i++){ll a;
        if(i==0){
            a=(B+1)%4;
            if(a==0||a==1)Bcount[0]=0;
            else Bcount[0]=1;
            continue;
        }
        else a=(ll)(B+1)%(1LL<<(i+1));
        Bcount[i]=(ll)max(0LL,a-(1LL<<i))%2;
    ;}
    ll ans=0;
    for(ll i=0;i<50;i++){
        if(Acount[i]!=Bcount[i])ans+=(1LL<<i);
        //cout<<ans<<endl;
    ;}
    cout<<ans<<endl;
    /*for(ll i=0;i<5;i++){
        cout<<Acount[i]<<endl;
    ;}cout<<endl;
    for(ll i=0;i<5;i++){
        cout<<Bcount[i]<<endl;
    ;}*/
    
    return 0;
}
