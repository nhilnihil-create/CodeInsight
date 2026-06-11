#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Ans = 0, count = 0, M, m;cin >> N;
vector<ll> V(N);

rep(i, 0, N){

    cin >> V[i];

    if(V[i] < 0){count++;Ans -= V[i];}

    else Ans += V[i];

    if(abs(V[i]) < M){M = abs(V[i]);m = i;}

}

if(count%2 == 0)cout << Ans;

else{
    
    if(V[m] < 0)cout << Ans + 2*V[m];

    else cout << Ans - 2*V[m];

}

}