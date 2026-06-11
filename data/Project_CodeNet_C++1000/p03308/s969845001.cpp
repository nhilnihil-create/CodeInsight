#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
using namespace std;
const long MOD=1e9+7;
template<class T>
T lcm(T a,T b){
    return a/__gcd(a,b)*b;
}

int main(){
    long n;cin >> n;
    vector<long> a(n);
    long ans=-1;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,abs(a[i]-a[j]));
        }
    }
    cout << ans;
    return 0;
}