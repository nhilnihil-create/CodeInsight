#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,inf=mod*mod*3ll;;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

string S;
ll K;
int main(){

cin.tie(0);
ios::sync_with_stdio(false);
cin>>S>>K;
if(S.size()==1){
    cout<<S[0]<<endl;
    return 0;
}
if(S[0]!='1'){
    cout<<S[0]<<endl;
}else{
    ll x=1; char y='1';
    rep(i,S.size()){
        if(S[i]!='1'){
            x=i+1; 
            y=S[i];
            break;
        }
    }
    if(K<=x-1){
        cout<<1<<endl;
    }else{
        cout<<y<<endl;
    }
}

}
	
