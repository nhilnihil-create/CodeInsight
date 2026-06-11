#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll N, total = 0;cin >> N;
vector<ll> A(N);

rep(i, 0, N){
cin >> A[i];

if(i == 0)total += abs(0 - A[i]);

else total += abs(A[i] - A[i - 1]);

}

total+=abs(A[N - 1]);

rep(i, 0, N){

if(i == 0)cout << total - abs(0 - A[i]) - abs(A[i] - A[i + 1]) + abs(0 - A[i + 1]) << endl;

if(i != 0 && i != N - 1)cout << total - abs(A[i - 1]  - A[i]) - abs(A[i + 1] - A[i]) + abs(A[i - 1] - A[i + 1]) << endl;

if(i == N - 1)cout << total - abs(A[i - 1] - A[i]) - abs(A[i]) + abs(A[i - 1]) << endl;

}

}