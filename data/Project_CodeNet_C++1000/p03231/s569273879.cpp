#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int GCD(int a, int b){
    if(b == 0) return a;
    else return GCD(b, a % b);
}

int main(){
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    int gcd = GCD(N, M);
    int n = N / gcd;
    int m = M / gcd;
    rep(k, gcd){
        if(S[k * n] != T[k * m]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << (ll)gcd * n * m << endl;
    return 0;
}