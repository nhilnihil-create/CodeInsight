#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll N, M;cin >> N;
vector<ll> V(5);

rep(i, 0, 5)cin >> V[i];

M = *min_element(ALL(V));

if(N%M == 0)cout << N / *min_element(ALL(V)) + 4;

else cout << N / *min_element(ALL(V)) + 5;

} 