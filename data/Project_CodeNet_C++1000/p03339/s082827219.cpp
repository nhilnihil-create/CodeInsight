#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Ans = pow(10, 6);cin >> N;
string S;cin >> S;
vector<pair<ll, ll>> A(N);
pair<ll, ll> total{0, 0};

rep(i, 0, N){
if(i != 0){A[i].first = A[i - 1].first;A[i].second = A[i - 1].second;}

if(S[i] == 'W')A[i].first++;
else A[i].second++;
}

rep(i, 0, N){
if(S[i] == 'W')total.first++;
else total.second++;
}

//rep(i, 0, N)cout << A[i].first << " " << A[i].second << endl;

rep(i, 0, N){

if(S[i] == 'W'){
Ans = min(A[i].first - 1 + total.second - A[i].second, Ans);
}

if(S[i] == 'E'){
Ans = min(A[i].first + total.second - A[i].second, Ans);
}
}
cout << Ans;
}