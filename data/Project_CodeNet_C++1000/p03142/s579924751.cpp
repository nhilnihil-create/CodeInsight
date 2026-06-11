#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

vector<int> G[100100];
vector<int> K;
vector<int> ANS;
int N, M;

void topology(){
    queue<int> S;
    REP(i,N){
        if(K[i] == 0){
            ANS[i] = 0;
            S.push(i);
        }
    }

    while(!S.empty()){
        int v = S.front();
        S.pop();
        for(auto&& n : G[v]){
            K[n]--;
            if(K[n] == 0){
                ANS[n] = v+1;
                S.push(n);
            }
        }
    }
}

int main(){
    cin >> N >> M;
    K.resize(N, 0);
    REP(i,N+M-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        K[b] += 1;
    }

    ANS.resize(N);

    topology();

    REP(i,N){
        cout << ANS[i] << endl;
    }

    return 0;
}
