#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
//input
int N,K;


//processing
ld ka;


//dpTable
//int dp[100050];

int main(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++){
        int a = i;
        ld hoge = 1;
        while (a < K){
            a *= 2;
            hoge /= 2;
        }
        ka += hoge;
    }
    cout << fixed << setprecision(10) << ka / N << endl;
    return 0;
}