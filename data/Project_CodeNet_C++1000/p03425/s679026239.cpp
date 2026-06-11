#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll N;
    cin >> N;
    vector<string> names(N);
    ll M,A,R,C,H;
    M = 0;
    A = 0;
    R = 0;
    C = 0;
    H = 0;
    ll ans = 0;
    vector<ll> a(5,0);
    sort(names.begin() , names.end());
    for(int i = 0; i < N; i++){
        cin >> names[i];
        if(names[i][0] == 'M') a[0]++;
        if(names[i][0] == 'A') a[1]++;
        if(names[i][0] == 'R') a[2]++;
        if(names[i][0] == 'C') a[3]++;
        if(names[i][0] == 'H') a[4]++;
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 5; k++){
                ans += a[i] * a[j] * a[k];
            }
        }
    }


    cout << ans << endl;

    
    
}
