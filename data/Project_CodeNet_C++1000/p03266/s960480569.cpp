#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, K;cin >> N >> K;

if(K%2 == 0)cout << ( ( N + K/2)/K )*( ( N + K/2)/K )*( ( N + K/2)/K ) + (N/K)*(N/K)*(N/K);

else cout << (N/K)*(N/K)*(N/K);

}