#include <bits/stdc++.h>
#include <cstdio>
#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define nln cout << '\n'
#define ll long long int
#define INF (ll)1e+12
#define MAX 300100
#define mp(i, j) make_pair(i, j)
#define here cout  << "here";nln;
#define mul(a, b, mod) (((a % mod) * (b % mod)) % mod)
#define add(a, b, mod) (((a % mod) + (b % mod)) % mod)
#define inf 100000
#define M 1000000000LL

using namespace std;

int main()
{
    ll n;

    ll i, ans = 0, j, k;

    cin >> n;

    vector <pair <ll , ll> > v;

    for(i = 1, j = (n>>1)*2; i < j; i++, j--){
        for(k = i+1; k < j; k++){
            v.push_back(make_pair(i, k));
            v.push_back(make_pair(j, k));
        }
        if(n&1)v.push_back(make_pair(i, n)), v.push_back(make_pair(j, n));
    }


    cout << v.size() << endl;

    for(i = 0; i < v.size(); i++)cout << v[i].first << ' ' << v[i].second << endl;

}
