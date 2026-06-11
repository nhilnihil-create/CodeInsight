#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Mod 998244353

int main(){
    ll n;
    int i,j;
    cin>>n;

    ll m=n*2;
    ll a=1;
    while(a*a<=m) a++;
    a--;
    if(a*(a+1)==m){
        vector<ll> v[a+1];
        ll k=a+1;
        ll loop=1;

        for(i=0;i<k;i++){
            for(j=i+1;j<k;j++){
                v[i].push_back(loop);
                v[j].push_back(loop);
                loop++;
            }
        }

        /*
        ll comb=(1<<2) -1;
        ll loop=1;
        while(comb< 1<<k){
            for(i=0;i<k;i++){
                if(comb>>i &1==1) v[i].push_back(loop);
            }
            loop++;
            ll x=comb&-comb;
            ll y=comb+x;
            comb=((comb&~y)/x>>1)|y;
        }*/

        cout<<"Yes"<<endl;
        cout<<k<<endl;
        for(i=0;i<k;i++){
            cout<<k-1;
            for(j=0;j<v[i].size();j++) {
                cout<<" "<<v[i][j];
            }
            cout<<endl;
        }  
    }
    
  /*if(n==1) {
        cout<<"Yes"<<endl;
        cout<<2<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 1"<<endl;
    }
    else if(n==3){
        cout<<"Yes"<<endl;
        cout<<3<<endl;
        cout<<"2 1 2"<<endl;
        cout<<"2 3 1"<<endl;
        cout<<"2 2 3"<<endl;
    }*/
    else {
        cout<<"No"<<endl;
    }
    return 0;
}
