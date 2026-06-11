#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = 1e18;

ll pow(int x, int n){
    if(n==0)return 1;
    else return x * pow(x, n-1);
}

int main(){
    int N;
    cin >> N;

    vector<ll> dp(N+1, INF);
    dp.at(0) = 0;

    for(int i=0; i<N; i++){
        dp.at(i+1) = min(dp.at(i+1), dp.at(i)+1);
        for(int j=1; i+pow(6,j)<=N; j++)
            dp.at(i+pow(6,j)) = min(dp.at(i+pow(6,j)), dp.at(i)+1);
        for(int k=1; i+pow(9,k)<=N; k++)
            dp.at(i+pow(9,k)) = min(dp.at(i+pow(9,k)), dp.at(i)+1);
    }

    cout << dp.at(N) << endl;
}