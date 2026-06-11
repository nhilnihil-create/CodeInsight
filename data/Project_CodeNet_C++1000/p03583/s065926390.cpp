#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
    ll n; cin >> n;

    vector<ll> vec(3500);
    rep(i, 3500) vec[i] = i + 1;
    ll num;
    for(int i = 1; i <= 3500; i++){
        for(int j = 1; j <= 3500; j++){
            if(4 * i * j - (i + j) * n != 0){
                num = (n * i * j) / (4 * i * j - (i + j) * n);
                if((n * i * j) % (4 * i * j - (i + j) * n) != 0) continue;
                if(binary_search(vec.begin(), vec.end(), num)){
                    cout << i << " " << j << " " << num << endl;
                    return 0;
                }
            } 
        }
    }
}