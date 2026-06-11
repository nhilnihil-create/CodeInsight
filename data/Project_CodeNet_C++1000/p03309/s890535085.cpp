#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

int main(){
ll N, Ans = 0;cin >> N;
vector<ll> A(N);
vector<ll> B(N);

rep(i, 0, N){

  cin >> A[i];

  B[i] = A[i] - i - 1;

}

sort(ALL(B));

rep(i, 0, N/2){

  Ans += B[N - 1 - i] - B[i];

}

cout << Ans;

}