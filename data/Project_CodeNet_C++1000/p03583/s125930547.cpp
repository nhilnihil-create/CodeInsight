#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    ll N; cin >> N;

    for(int i = 1; i <= 3500; i ++){
        for(int j = 1; j <= 3500; j ++){
            if((4*i*j - N*i - N*j) != 0 && (N*i*j)%(4*i*j - N*i - N*j) == 0){
                if(((N*i*j)/(4*i*j - N*i - N*j)) <= 0 ) continue;
                cout << i << " " << j << " " << ((N*i*j)/(4*i*j - N*i - N*j));
                return 0;
            }
        }
    }

}
