#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int A, B, C, K; cin >> A >> B >> C >> K;
    for(int i = 0; i < K; i++) {
        int M = max(max(A, B), C);
        if(M == A) A *= 2;
        else if(M == B) B *= 2;
        else C *= 2;
    }
    cout << A + B + C << endl;
}