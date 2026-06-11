#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(int i=a;i<n;i++)

ll F(ll a){
    ll res=0;
    while(a>0){
        res+=a%10;
        a/=10;
    }
    return res;
}

double S(ll a){
    double res=(double)a/F(a);
    return res;
}

int main(){
    ll k;cin >> k;

    vector<ll> res;
    ll base=1;
    rep(i,0,15){
        rep(j,1,140){
            res.push_back(base*(j+1)-1);
        }
        base*=10;
    }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    rep(i,0,res.size()){
        rep(j,i+1,res.size()){
            if(S(res[i])>S(res[j])){
                res.erase(res.begin()+i--);
                break;
            }
        }
    }

    rep(i,0,k){
        cout << res[i] << endl;
    }
}