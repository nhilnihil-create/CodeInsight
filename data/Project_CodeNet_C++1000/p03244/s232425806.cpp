#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, a1 = 0, b1 = 0, a2 = 0, b2 = 0;cin >> N;
map<ll, ll> A;
map<ll, ll> B;

rep(i, 0, N/2){

    ll a, b;cin >> a >> b;

    A[a]++;B[b]++;

}
  
ll x, y;
  
//for(auto a : A )cout << a.first << " " << a.second << endl;
//  cout << endl;
//for(auto b : B )cout << b.first << " " << b.second << endl;

for(auto a : A )a1 = max(a1, a.second);
  
for(auto a : A ){
  if(a.second == a1)x = a.first;
}

for(auto b : B )b1 = max(b1, b.second);
  
for(auto b : B ){
  if(b.second == b1)y = b.first;
}

//cout << x << " " << y << endl;
  
A[x] = -1;
B[y] = -1;

for(auto a : A )a2 = max(a2, a.second);

for(auto b : B )b2 = max(b2, b.second);
  
//cout << a1 << " " << b1 << endl;
//cout << a2 << " " << b2 << endl;
//cout << x << " " << y << endl;

if(x == y)cout << min(N - a1 - b2, N - b1 - a2);

else cout << N - a1 - b1;

}