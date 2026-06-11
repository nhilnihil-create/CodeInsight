#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    int a, b;
    vector<int> v(N, 0);
    for (int i = 0; i < N + M - 1; i++) {
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        v[b]++;
    }
    int ind = 0;
    for (int i = 0; i < N; i++) {
        if(v[i] == 0){
            ind = i;
            break;
        }
    }
    queue<int> q;
    vector<int> par(N, 0);
    par[ind] = 0;
    q.push(ind);
    while(!q.empty()) {
        int w = q.front(); q.pop();
        for (int x : G[w]){
            v[x]--;
            if(v[x] == 0){
                q.push(x);
                par[x] = w+1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", par[i]);
    }
    


}