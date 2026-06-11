#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int max_n = max({A, B, C});
    int min_n = min({A, B, C});
    int mid_n = A + B + C - max_n - min_n;
    int count = 0;
    while(mid_n != max_n){
        mid_n++;
        min_n++;
        count++;
    }
    while(min_n < max_n){
        min_n+=2;
        count++;
    }
    if(min_n == max_n + 1) cout << count + 1 << endl;
    else cout << count << endl;
}
