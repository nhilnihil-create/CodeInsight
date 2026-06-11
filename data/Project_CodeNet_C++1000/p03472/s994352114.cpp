#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,h;
ll a[100005],b[100005];

int main(){
    cin >> n >> h;
    for(ll i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    sort(a,a+n,greater<ll>());
    sort(b,b+n,greater<ll>());
    vector<ll> vec;
    vec.push_back(0);
    for(ll i=0;i<n;i++){
        ll memo=vec[vec.size()-1];
        if(b[i]>a[0]){
            memo+=b[i];
            vec.push_back(memo);
        }
        else{
            break;
        }
    }
    ll m=vec.size();
    if(vec[m-1]>=h){
        ll ng=0;
        ll ok=m;
        while(abs(ok-ng)>1){
            ll mid=(ng+ok)/2;
            if(vec[mid]>=h) ok=mid;
            else ng=mid;
        }
        cout << ok << endl;
    }
    else{
        cout << m-1+(h-vec[m-1]+a[0]-1)/a[0] << endl;
    }
}
