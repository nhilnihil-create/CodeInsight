#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    ll a[n];
    rep(i, 0, n){
        cin >> a[i];
    }

    if(a[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    ll count = 0;
    rep(i, 1, n){
        if(a[i] > a[i - 1] + 1){
            cout << -1 << endl;
            return 0;
        }else{
            if(a[i] == a[i - 1] + 1){
                count++;
            }else{
                count += a[i];
            }
        }
    }

    cout << count << endl;
    return 0;
}
