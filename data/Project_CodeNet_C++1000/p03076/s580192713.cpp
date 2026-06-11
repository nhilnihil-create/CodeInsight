#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    vector<ll> time;
    ll tmp;
    ll mamr=9;
    ll amr=0;
    ll min=0;
    rep(i,5){
        cin>>tmp;
        time.push_back(tmp);
        amr = tmp%10;
        if(amr!=0){
            if(amr<=mamr){
                min=i;
                mamr=amr;
            }
        }
    }
    // cout<<min<<":"<<mamr<<endl;
    ll ans=0;
    rep(i,5){
        tmp = time[i];
        if(i!=min){
            if(tmp%10!=0){
                tmp=tmp-tmp%10+10;
            }
        }
        ans+=tmp;
    }
    cout<<ans<<endl;



}

