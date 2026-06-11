#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n; cin >> n;   
    vector<int> v;

    for(int i = 3; i <= 55555; i++){
        bool pri = true;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0) pri = false;
        }
        if(pri && i % 5 == 1) v.push_back(i);
    }
    rep(i,n) cout << v[i] << ' ';
}