#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;

//input
string S;

//processing
int ans;


//dpTable
//int dp[100050];

int main(){
    cin >> S;
    if (S.at(0) == '1') ans++;
    if (S.at(1) == '1') ans++;
    if (S.at(2) == '1') ans++;
    cout << ans << endl;
    return 0;
}
