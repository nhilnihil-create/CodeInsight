#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;

int DP[505][505];

int main() {
    int N, M, Q;
    cin>>N>>M>>Q;
    int L, R;
    for(int i=0;i<M;++i){
        cin>>L>>R;
        DP[L][R]++;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            DP[i][j] += DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1];
        }
    }
    int p, q;
    int ans[Q];
    for(int i=0;i<Q;++i){
        cin>>p>>q;
        ans[i] = DP[q][q] - DP[q][p-1] - DP[p-1][q] + DP[p-1][p-1];
    }
    for(int i=0;i<Q;++i){
        cout<<ans[i]<<endl;
    }
}
