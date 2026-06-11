#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    ll n,k;
    cin>>n>>k;
    ll a[n];
    map<int,int> d;
    rep(i,40){
        d[i]=0;
    }
    rep(i,n){
        cin>>a[i];
        bitset<40> s(a[i]);
        rep(i,40){
            if (s.test(i)){
                d[i]+=1;
            }
        }
    }
    ll num=1;
    rep(i,40){
        num*=2;
    }
    ll ans=0;
    ll now=0;
    for (int i=39;i>=0;i--){
        num/=2;
        if (d[i]>n/2){
            ans+=num*d[i];  
        }
        else{
            if (now+num>k){
                ans+=num*d[i];
            }
            else{
                now+=num;
                ans+=num*(n-d[i]);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}