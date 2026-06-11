#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;

int main(){
    string S;
    ll K;
    cin >> S >> K;
    rep(i,S.size()){
        K--;
        if(K == 0 || S[i] != '1'){
            cout << S[i] << endl;
            return 0;
        }
        
    }
}
