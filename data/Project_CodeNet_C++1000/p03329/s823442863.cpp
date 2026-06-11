#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

//繰り返し二乗法
ll EX(ll x,ll n){
    if(n == 0) return 1;
    else if(n%2 == 1) return EX(x,n-1)*x;
    else return EX(x*x,n/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    int dp[100000+10];
    int d[2] = {6,9};

    for(int i = 0; i <= n; i++) dp[i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 10; k++){
                if(EX(d[j],k) <= i) dp[i] = min(dp[i],dp[i-EX(d[j],k)]+1); 
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}