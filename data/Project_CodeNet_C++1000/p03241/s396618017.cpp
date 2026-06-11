#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int main()
{
    int n,m; cin >> n >> m;
    vector<ll> x;
    for(int i = 1; i*i <= m; i++){
        if(m % i == 0){
            if(m == i*i){
                x.push_back(i);
            }else{
                x.push_back(i);
                x.push_back(m/i);
            }
        }
    }
    sort(all(x));
    reverse(all(x));
    if(m%n==0){
        cout << m/n << endl;
    }else{
        ll k = m/n; 
        for(int i = 0; i < n; i++){
            if(x[i] <= k){
                cout << x[i] << endl;
                break;
            }
        }
    }
}