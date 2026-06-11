#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
//input
string S,T;

//processing



//dpTable
//int dp[100050];

int main(){
    cin >> S >> T;
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    reverse(T.begin(),T.end());
    if (S < T) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
