#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int count = 0;
    for(int a = 0;  a <= A; a++){
        for(int b = 0; b <= B; b++){
            for(int c = 0; c <= C; c++){
                if(500 * a + 100 * b + 50 * c == X) count++;
            }
        }
    }
    cout << count << endl;
}
