#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll N, M;cin >> N >> M;
vector<ll> A(M);
vector<ll> B(M);
rep(i, 0, M)cin >> A[i] >> B[i];
if(*min_element(ALL(B)) - *max_element(ALL(A)) + 1 < 0){cout << 0;exit(0);}
cout << *min_element(ALL(B)) - *max_element(ALL(A)) + 1;
}