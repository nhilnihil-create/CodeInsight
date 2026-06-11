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
ll A = INF;


//dpTable
//int dp[100050];

int main(){
    cin >> N >> K;
    vector<ll> h(N);
    rep (i,N) cin >> h.at(i);
    sort(h.begin(),h.end());
    for (int i = 0; i < N - K + 1; i++){
        A = min(A,h.at(i + K - 1) - h.at(i));
    }
    cout << A << endl;
    return 0;
}