
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;

    vector<ll> x(n);
    rep(i,n) cin >> x[i];

    vector<ll> y(n);
    rep(i,n) y[i] = x[i];
    sort(all(y));
    ll cent1 = y[(n/2)-1];
    ll cent2 = y[n/2];

    for(int i=0; i<n; i++){
        if(x[i] <=cent1){
            cout << cent2 << endl;
        }
        else{
            cout << cent1 << endl;
        }
    }


}