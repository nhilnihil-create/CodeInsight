#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int (i) = (a);(i) < (b);i++)
#define Rep(i,n) For((i),0,(n))
#define All(a) (a).begin(),(a).end()
#define sp " "
#define INF 1e18
#define INT_INF 1e9

typedef long long ll;
const ll MOD = 1000000007;
const ll MOD_9 = 998244353;

int N;

int main(){
    cin >> N;
    vector<int> C(N+1);
    vector<int> F(200010,0);
    long long DP[N+1];
    DP[0] = 1;
    Rep(i,N)cin >> C[i+1];
    Rep(i,N){
        if(F[C[i+1]] == 0)DP[i+1] = DP[i];
        else if(F[C[i+1]] == i)DP[i+1] = DP[i];
        else DP[i+1] = DP[i] + DP[F[C[i+1]]];
        F[C[i+1]] = i+1;
        DP[i+1] %= MOD;
        //cout << DP[i+1] << endl;
    }
    cout << DP[N] << endl;
    //cin >> N;
}