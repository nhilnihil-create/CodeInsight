#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n, x;
map<ll, ll> mp;

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        cin >> n>> x;
        ll an = 1;
        for (ll i = 2; i*i <= x; i++)
                while (x % i == 0) {
                        x /= i;
                       mp[i]++;
                }
        if (x > 1) {
                mp[x]++;
        }
        for (auto s: mp) {
                if (s.second >= n)
                        an *= (ll)pow(s.first, s.second / n);
        }
        cout << an  ;
return 0;
}
