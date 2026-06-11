#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i=0; i<(int)(n); i++)
#define REP2(i,x,n) for(int i=x; i<(int)(n); i++)
#define VSORT(v) sort(v.begin(), v.end());
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
int main(){
    ll a, b;
    cin >> a >> b;
    ll c = a * b;
    ll d = c % 2;
    if (d == 0) {
        cout << "Even" << endl;
    }
    else {
        cout << "Odd" << endl;
    }
}