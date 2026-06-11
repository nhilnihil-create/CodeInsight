#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N;cin >> N;
vector<ll> C(N);
vector<ll> S(N);
vector<ll> F(N);
vector<ll> Ans(N, 0);

rep(i, 1, N)cin >> C[i] >> S[i] >> F[i];

rep(i, 1, N + 1){

    if(i == N){cout << 0;break;}

    rep(j, i, N){

        if(S[j] >= Ans[i])Ans[i] = S[j] + C[j];

        else{

            if(Ans[i]%F[j] != 0)Ans[i] = F[j]*(Ans[i]/F[j] + 1) + C[j];

            else Ans[i] += C[j];

        }
    }

    cout << Ans[i] << endl;
    
}
}