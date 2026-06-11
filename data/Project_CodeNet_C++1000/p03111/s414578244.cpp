#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<int> V(10);
vector<int> T(10);
int N;
int ans = 1001001001;
int INF = 1001001001;
int A, B, C;

void calc(vector<int> v){
    int now = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < N; i++){
        if(v[i] == 0){
            if(a != 0){
                now += 10;
            }
            a += T[i];
        } else if(v[i] == 1){
            if(b != 0){
                now += 10;
            }
            b += T[i];
        } else if(v[i] == 2){
            if(c != 0){
                now += 10;
            }
            c += T[i];
        } else {
            continue;
        }
    }
    if(a == 0 || b == 0 || c == 0){
        now = INF;
    } else {
        now += abs(A-a) + abs(B-b) + abs(C-c);
    }

    ans = min(ans, now);
    
    return;
}

void dfs(int depth, vector<int> &v){
    if(depth == N){
        calc(v);
    } else {
        for (int i = 0; i < 4; i++){
            v[depth] = i;
            dfs(depth+1, v);
        }
    }
    return;
}

int main() {
    cin >> N >> A >> B >> C;
    rep(i, N){
        cin >> T[i];
    }

    dfs(0, V);

    cout << ans << endl;

    return 0;
}