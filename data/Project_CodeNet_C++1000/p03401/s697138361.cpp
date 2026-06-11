#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int n; cin >> n;
    vector<ll> a(n+2,0);
    rep2(i,n+1){
        cin >> a[i];
    }
    ll sum=0;
    rep2(i,n+2){ // n+1回繰り返す。
        sum+=abs(a[i]-a[i-1]);
    }
    rep2(i,n+1){ // n回繰り返す。
        if((a[i]-a[i-1])*(a[i]-a[i+1])>0){
            cout << sum - abs(a[i]-a[i-1]) - abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]);
        }else cout << sum;
        cout << endl;
    }
}