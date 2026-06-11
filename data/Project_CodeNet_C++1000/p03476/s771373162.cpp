#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

// 素数
bool is_prime(ll n){
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

vector<int> a(100010);

int main(){
    for(int i=1;i<100010;i+=2){
        if(is_prime(i) && is_prime((i+1)/2)){
          a[i]=1;
        }
    }

    vector<ll> s(100010,0);
    rep(i,100010){
      s[i+1]=s[i]+a[i];
    }
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        r++;
        cout<<s[r]-s[l]<<endl;
    }
    return 0;
}
