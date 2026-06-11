#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i <= N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, M;cin >> N >> M;
vector<ll> div;

rep(i, 1, sqrtl(M)){
    
    if(M%i == 0){
        
        div.push_back(i);div.push_back(M/i);

    }

}

sort(ALL(div));//for(auto v : div)cout << v << " ";

ll a, L = div.size();

rep(i, 0, L - 1){

    if(N <= div[i]){a = div[i];break;}

}

cout << M/a;

}