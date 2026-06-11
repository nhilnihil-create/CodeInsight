#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, k;
    cin >> n >> k;

    ll sum = 0;
    rep(i, 1, n + 1){
        if(i <= k){
            continue;
        }else{
            sum += (n / i - 1) * (i - k);
            if(k != 0){
                if(n % i - k + 1 > 0){
                    sum += n % i - k + 1;
                }
            }else{
                if(n % i - k > 0){
                    sum += n % i - k;
                }
            }
            sum += i - k;
        }
    }

    cout << sum << endl;
    return 0;
}
