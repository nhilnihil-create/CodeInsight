#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> dp(M+1);
    rep0(i,N){
        int K;
        cin >> K;
        rep0(j,K){
            int input ;
            cin >> input;
            dp[input]++;
        }
    }
    int res = 0;
    rep1(i,M){
        if(dp[i]==N){
            res++;
        }
    }
    cout << res << endl;
}
