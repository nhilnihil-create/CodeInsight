#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0){ return a;}
    else {
        return gcd(b, a % b);
    }
}

ll gcdVect(vector<ll> & vals){
    int size = vals.size();
    ll gcdVal = vals[0];
    for(int i = 1 ; i < size; i++){
        gcdVal = gcd(max(vals[i], gcdVal), min(vals[i], gcdVal));
    }
    return gcdVal;
}

int main(void)
{
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N, 0);
    
    
    for (ll i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    vector<ll> distX(N, 0);

    for( ll i = 0; i < N; i++){
        distX[i] = abs(X - x[i]);
    }

    ll val = gcdVect(distX);

    cout << val << endl;
    return 0;
}
