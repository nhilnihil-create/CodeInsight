#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll N, a, b;cin >> N;
vector<ll> A(N);
vector<ll> B(N);

rep(i, 0, N){
cin >> A[i];
}

B = A;
sort(ALL(A));

a = A[N/2 - 1];b = A[N/2];

rep(i, 0, N){
if(B[i] <= a){cout << b << endl;continue;}
if(B[i] >= b)cout << a << endl;
}

}