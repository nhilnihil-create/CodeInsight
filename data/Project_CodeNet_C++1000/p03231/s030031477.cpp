#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;

ll gcd(ll a, ll b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}


int main() {

    ll n,m; cin >> n >> m;
    vector<ll> np,mp;
    string s,t; cin >> s >> t;
    ll g = lcm(n,m);
    ll nPos = 0,mPos = 0;

    for(int i = 0; i < n; i ++){
        np.push_back(1+i*(g/n));
    }
    for(int i = 0; i < m; i ++){
        mp.push_back(1+i*(g/m));
    }



    while(nPos != np.size() && mPos != mp.size()){
        if(np[nPos] == mp[mPos]){
            if(s[nPos] != t[mPos])
            {
                cout << -1;
                return 0;
            }
            nPos ++;
            mPos ++;
        }else if(np[nPos] > mp[mPos]) mPos ++;
        else nPos ++;
    }

    cout << g;


    return 0;
}
