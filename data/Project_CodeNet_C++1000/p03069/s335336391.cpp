#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

int main(){
ll N, Ans = 0, wt = 0;cin >> N;
string S;cin >> S;
vector<ll> V(N);

if(S[0] == '.')wt++;

rep(i, 1, N){

  V[i] = V[i - 1];

  if(S[i - 1] == '#')V[i]++;

  if(S[i] == '.')wt++;

}

Ans = wt;

rep(i, 0, N){

  ll A = 2*V[i] + wt - i;

  if(S[i] == '.')A--;

  else A++;

  Ans = min(Ans, A);//cout << A << endl;

}

cout << Ans;

}