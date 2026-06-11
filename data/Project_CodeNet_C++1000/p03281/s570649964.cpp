#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

vector<ll> divisor(ll n){
    vector<ll> ret;
    for (ll i = 1; i * i <= n;i++){
        if(n%i==0){
            ret.push_back(i);
            if(i*i!=n)
                ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i += 2){
        vector<ll> hoge = divisor(i);
        if(hoge.size() == 8)
            ans++;
    }
    cout << ans << endl;
    return 0;
}