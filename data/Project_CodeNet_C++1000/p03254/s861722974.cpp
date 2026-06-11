#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());
    ll sum=0;
    int cnt=0;
    rep(i,n){
        sum+=a.at(i);
        cnt++;
        if(sum>x)break;
    }
    if(sum==x)cout << cnt << endl;
    else cout << cnt-1 << endl;
}



    
   
