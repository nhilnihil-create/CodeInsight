#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int N, K;
vector<int> V;
int main(void){
    cin >> N >> K;
    int v;
    REP(i,N){
        cin >> v;
        V.push_back(v);
    }
    ll total = -1;
    for(int l=0;l<=min(N, K);l++){
        for (int r=0;r<=min(N, K)-l;r++){
            vector<int> v;
            for(int i=0;i<l;i++) v.push_back(V[i]);
            for(int i=0;i<r;i++) v.push_back(V[N-i-1]);
            sort(v.begin(), v.end());
            REP(i, min(K-(r+l), int(v.size()))) v[i] = max(v[i], 0);
            ll t = 0;
            REP(i, v.size()) t += v[i];
            total = max(total, t);
        }
    }
    cout << total << endl;
    return 0;
}

