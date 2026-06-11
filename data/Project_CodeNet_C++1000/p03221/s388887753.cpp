#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> Y[i];
    }

    vector<vector<iint>> G(N+1);

    for (int i = 0; i < M; i++) {
        G[P[i]].push_back(make_pair(Y[i], i));
    }

    for (int i = 0; i < N+1; i++) {
        if(G[i].size() > 0){
            sort(ALL(G[i]));
        }
    }

    vector<int> x(M);
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            x[G[i][j].second] = j+1;
        }
    }

    for (int i = 0; i < M; i++) {
        printf("%06d%06d\n", P[i], x[i]);
    }

}