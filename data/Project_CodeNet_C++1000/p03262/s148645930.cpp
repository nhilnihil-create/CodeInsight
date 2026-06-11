#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

ll gcd(ll N, ll M){

if(N%M == 0)return M;

else return gcd(M, N%M);

}

int main(){
ll N, X, Ans = 0;cin >> N >>X;

if(N == 1){
ll a;cin >> a;
cout << abs(X - a);
exit(0);
}

rep(i, 0, N - 1){

if(i == 0){
ll a, b;cin >> a >> b;
Ans = gcd( abs(X - a), abs(X - b) );
}

else{
ll a;cin >> a;
Ans = gcd( Ans, abs(X - a) );
}

}


cout << Ans;
}