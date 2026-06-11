#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, Ans = 0, a;cin >> N;
map<int, int> M;

rep(i, 0, N){
cin >> a;
M[a]++;
}

for(auto x : M){
if(x.first > x.second)Ans += x.second;
else Ans += x.second - x.first;
}
cout << Ans;
}