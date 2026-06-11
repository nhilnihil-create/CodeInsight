#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
//#define for(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, Ans = 0;;cin >> N;
vector<ll> A(5);

for(int i = 0; i < N; i++){
string S;cin >> S;

if(S[0] == 'M')A[0]++;
if(S[0] == 'A')A[1]++;
if(S[0] == 'R')A[2]++;
if(S[0] == 'C')A[3]++;
if(S[0] == 'H')A[4]++;

}

for(int i = 0; i < 5; i++){
for(int j = i + 1; j < 5; j++){
for(int k = j + 1; k < 5; k++){

Ans += A[i]*A[j]*A[k];

}}}
cout << Ans;
}