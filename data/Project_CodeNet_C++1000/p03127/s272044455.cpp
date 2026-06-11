#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll N, M, count = 0;cin >> N;
vector<ll> A(N);

M = N;

rep(i, 0, N)cin >> A[i];

sort(ALL(A));

while(M >= 2){

    rep(i,1, M){
    if(A[i]%A[0] == 0){A[i] = powl(10, 9);count++;}
    else A[i] %= A[0];
    }

M = N - count;
 
sort(ALL(A));

}

cout << A[0];

}