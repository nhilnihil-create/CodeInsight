#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

vector<int> G[200100];
int d[200100];
bool isvisit[200100];

void dfs(int v, int c){
    isvisit[v] = true;
    d[v] = c;
    for(int i = 0; i < G[v].size(); i++){
        int next = G[v][i];
        if(isvisit[next]) continue;
        dfs(next, c+1);
    }
}

int main(){
    int N;
    cin >> N;
    REP(i,N-1){
        int a,b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, 0);
    int ma = -1;
    int idx;
    REP(i,N){
        int x = d[i];
        if(x > ma){
            ma = x;
            idx = i;
        }
    }

    fill(isvisit, isvisit+N, false);

    dfs(idx, 0);

    sort(d, d+N);

    int step = d[N-1] + 1;

    //cout << step << endl;
    int num = (step+1)%3;

    bool win;
    //cout << step << endl;
    if(step == 0){
        win = false;
    }
    else if(step == 1){
        win = true;
    }
    else if(num == 0){
        win = false;
    }
    else if(num == 1){
        win = true;
    }
    else if(num == 2){
        win = true;
    }


    if(win){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
    return 0;
}
