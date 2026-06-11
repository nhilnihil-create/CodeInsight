#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
//input
int N;
int A1[105];
int A2[105];

//processing
int ans,cnt;


//dpTable
//int dp[100050];

int main(){
    cin >> N;
    rep (i,N){
        cin >> A1[i];
    }
    rep (i,N){
        cin >> A2[i];
    }
    for (int i = 0; i <= N - 1; i++){
        for (int j = 0; j <= i; j++){
            cnt += A1[j];
        }
        for (int k = i; k <= N - 1; k++){
            cnt += A2[k];
        }
        ans = max(ans,cnt);
        cnt = 0;
    }
    cout << ans << endl;
    return 0;
}
