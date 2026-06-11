#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
    int n;
    ll m;
    cin >> n >> m;

    vector<ll> s;
    ll t = m / n;

    for(ll i = 1; i * i <= m; i++){
        if(m % i == 0){
            if(t >= i){
                s.push_back(i);
            }
            
            if(t >= (m / i)){
                s.push_back(m / i);
            }
        }
    }

    sort(s.begin(), s.end());

    cout << s[s.size() - 1] << endl;

}