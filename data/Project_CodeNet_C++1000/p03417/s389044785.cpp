#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, M;cin >> N >> M;

if(N == 1 && M == 1){cout << 1;exit(0);}
if(N == 2 || M == 2){cout << 0;exit(0);}
if(N == 1 && M != 1){cout << M - 2;exit(0);}
if(N != 1 && M == 1){cout << N - 2;exit(0);}
cout << (N - 2)*(M - 2);
}