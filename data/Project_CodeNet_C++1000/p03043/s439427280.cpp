#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
double N, K;cin >> N >> K;
double Ans = 0;

    rep(i, 1, N + 1){
    ll j = 0;

        while(i*pow(2, j) < K)j++;

    Ans += 1/(N*pow(2, j));
    }

cout << fixed << setprecision(12) << Ans;
}