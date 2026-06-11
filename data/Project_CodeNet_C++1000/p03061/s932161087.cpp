#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

//最大公約数を求める関数
ll gcd(ll a,ll b){
    ll c,d,e;
    c=max(a,b);
    d=min(a,b);
    while(1){
        c=c%d;
        if(c==0){
            break;
        }
        e=d;
        d=c;
        c=e;
    }
    return d;
}

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <vector <ll>> bb(18);
    rep(i,n){
        cin >> a[i];
        bb[0].push_back(a[i]);
    }

    
    ll n2;
    n2=n;
    ll l;
    int k3;
    

   rep(i,17){
        if(n2%2==1){
            l=bb[i].size();
           bb[i].push_back(bb[i][l-1]);
       }
       if(n2==1){
           k3=i;
           break;
       }
       n2=(n2+1)/2;
       
      
       rep(j,n2){
           bb[i+1].push_back(gcd(bb[i][2*j],bb[i][2*j+1]));
       }
   }

   //rep(i,k3){
   //    l=bb[i].size();
   //    cout << "  " << i << endl;
   //    rep(j,l){
   //        cout << bb[i][j] << endl;
   //    }
   //}

   ll k4=1,ans,k5=0;
   vector <int> b(17,0),b2(17,0);
   ll ans2;
   ans2=gcd(bb[k3-1][0],bb[k3-1][1]);

   rep(i,n){
       b=b2;
       k4=1;
       k5=0;
       ans=bb[k3-1][0]*bb[k3-1][1];
       rep(j,k3){
           b[j]=((i>>(k3-j-1))&1);
            k5+=b[j];
            //cout << i << " " << b[j] << endl;
            if(b[j]==0){
                ans=gcd(ans,bb[k3-j-1][k5+1]);
            }
            else{
                ans=gcd(ans,bb[k3-j-1][k5-1]);
            }
            k5*=2;
       }
       //cout << ans << endl;
       ans2=max(ans,ans2);
   }

   cout << ans2 << endl;


    

    return 0;
}