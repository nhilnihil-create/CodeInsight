//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    vector<ll>a(100000+10);
    a[0]=0;
    a[1]=0;
    a[2]=0;
    a[3]=1;
    a[4]=1;
    a[5]=2;
    a[6]=2;
    bool jud;
    for(ll i=7;i<=100000+10;i+=2){
        jud=true;
        for(ll j=2;j<=sqrt(i);j++){
            if(i%j==0){
                jud=false;
                break;
            }
        }
        for(ll k=2;k<=sqrt((i+1)/2);k++){
            if(((i+1)/2)%k==0){
                jud=false;
                break;
            }
        }
        if(jud){
            a[i]=a[i-1]+1;
            a[i+1]=a[i];
        }
        else{
            a[i]=a[i-1];
            a[i+1]=a[i];
        }
    }
    /*rep(i,10){
        cout<<a[i]<<endl;
        
    }
    return 0;*/
    ll q; cin>>q;
    vector<ll>l(q);
    vector<ll>r(q);
    rep(i,q){
        cin>>l[i]>>r[i];
    }
    rep(i,q){
        cout<<a[r[i]]-a[l[i]-1]<<endl;
    }

}

















































