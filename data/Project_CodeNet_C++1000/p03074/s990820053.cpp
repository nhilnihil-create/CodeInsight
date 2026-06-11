#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <ll> t;
    
    ll k3=0;
    int m;
    rep(i,n){
        //cout << "i" << i << endl;
        if(k3==0){
            if(s[i]=='0'){
                k3=1;
                m=1;
                t.push_back(0);
                
            }
            else{
                k3=-1;
                m=-1;
                
            }
        }
        else if(k3>0){
            if(s[i]=='0'){
                ++k3;
            }
            else{
                t.push_back(k3);
                k3=-1;
            }
        }
        else{
            if(s[i]=='1'){
                --k3;
            }
            else{
                t.push_back(k3*(-1));
                k3=1;
        }
    }
    }

    if(k3>0){
        t.push_back(k3);
    }
    else{
        t.push_back(k3*(-1));
    }

    ll l,l2=0;

    l=t.size();
    //cout << l << endl;
    if(l%2==0){
        t.push_back(0);
        ++l;
    }
    
    
    vector <ll> r(l);
    ll k2;
    ll ans=0,ans2;

    if(2*k+1>l){
        cout << n << endl;
    }
    else{
        rep(i,2*k+1){
            ans+=t[i];
            //cout << i << i << endl;
            //cout << t[i] << endl;
        }
        ans2=ans;
        k2=(l-2*k-1)/2+1;
        rep(i,k2-1){
            ans+=t[2*k+1+i*2]+t[2*k+2+i*2];
            ans-=t[i*2]+t[i*2+1];
            if(ans>ans2){
                ans2=ans;
            }
        }
        cout << ans2 << endl;
    }

    
    
    

    return 0;
}