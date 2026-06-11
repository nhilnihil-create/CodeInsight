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
    ll n;
    cin>>n;
    ll a[n];
    rep(i,n){
        cin>>a[i];
    }
    ll s=a[0],num=a[0],l=0,r=0;
    int b=1;//b=1の時rを増やす
    ll ans=1;
    while (r<n-1 || b==0 ){
        if (b==1){
            r+=1;
            num=num^a[r];
            s+=a[r];
            if (s==num){
                ans+=r-l+1;
            }
            else{
                b=0;
            }
        }
        else{
            num=num^a[l];
            s-=a[l];
            l+=1;
            if (s==num){
                ans+=r-l+1;
                b=1;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}