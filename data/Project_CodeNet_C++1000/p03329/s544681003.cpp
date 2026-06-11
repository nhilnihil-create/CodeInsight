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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int DP[100005];

int main() {
    int N;
    cin>>N;
    for(int i=0;i<=N;++i){
        DP[i] = inf;
    }
    DP[0] = 0;
    DP[1] = 1;
    for(int i=1;pow(6, i)<=N;++i){
        DP[int(pow(6, i))] = 1;
    }
    for(int i=1;pow(9, i)<=N;++i){
        DP[int(pow(9, i))] = 1;
    }
    for(int i=2;i<=N;++i){
        DP[i] = min(DP[i], DP[i-1]+1);
        for(int j=1;pow(6, j)<=i;++j){
            DP[i] = min(DP[i], DP[i-int(pow(6, j))] + 1);
        }
        for(int j=1;pow(9, j)<=i;++j){
            DP[i] = min(DP[i], DP[i-int(pow(9, j))] + 1);
        }
    }
    cout<<DP[N]<<endl;
}
