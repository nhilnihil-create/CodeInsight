#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
using ll = long long;
using uint = unsigned int;
using graph = std::vector<std::vector<ll>>;
using wGraph = std::vector<std::vector<std::pair<ll,ll>>>;
#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;
ll MOD7 = 1000000007;
ll MOD9 = 1000000009;
vector<ll> InputVec(ll N){
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    return A;
}
void OutputVec(vector<ll> A){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;
}
vector<vector<ll>> InputVec2d(ll H,ll W){
    vector<vector<ll>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            cin >> A[yi][xi];
        }
    }
    return A;
}
vector<vector<char>> InputVec2dStr(ll H,ll W){
    vector<vector<char>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<char>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        string S;
        cin >> S;
        for (int xi = 0; xi < W; ++xi) {
            A[yi][xi] = S[xi];
        }
    }
    return A;
}
void OutputVec2d(vector<vector<ll>> A){
    for (int yi = 0; yi < A.size(); ++yi) {
        for (int xi = 0; xi < A[yi].size(); ++xi) {
            cout << A[yi][xi] << ",";
        }
        cout << endl;
    }
}
graph InputGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return G;
}
graph InputDGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
    }
    return G;
}
void OutputGraph(graph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j]<< ",";
        }
        cout << endl;
    }
}
void OutputAnswerBool(bool b,bool isUpperCase = false){
    if(b){
        if(isUpperCase){
            cout << "YES" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }else{
        if(isUpperCase){
            cout << "NO" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

int main() {
    string s;
    cin >> s;
    ll N = s.size();
    ll memo[N][4];
    for (int yi = 0; yi < N; ++yi) {
        for (int xi = 0; xi < 4; ++xi) {
            memo[yi][xi] = 0;
        }
    }
    switch (s[0]){
        case 'A':
            memo[0][1] = 1;
            memo[0][0] = 1;
            break;
        case 'B':
            memo[0][0] = 1;
            break;
        case 'C':
            memo[0][0] = 1;
            break;
        case '?':
            memo[0][0] = 3;
            memo[0][1] = 1;
            break;
    }
    for (int i = 1; i < N; ++i) {
        char current = s[i];
        switch (current) {
            case 'A':
                memo[i][0] = memo[i-1][0];
                memo[i][1] = memo[i-1][1] + memo[i-1][0];
                memo[i][2] = memo[i-1][2];
                memo[i][3] = memo[i-1][3];
                break;
            case 'B':
                memo[i][0] = memo[i-1][0];
                memo[i][1] = memo[i-1][1];
                memo[i][2] = memo[i-1][2] + memo[i-1][1];
                memo[i][3] = memo[i-1][3];
                break;
            case 'C':
                memo[i][0] = memo[i-1][0];
                memo[i][1] = memo[i-1][1];
                memo[i][2] = memo[i-1][2];
                memo[i][3] = memo[i-1][3] + memo[i-1][2];
                break;
            case '?':
                memo[i][0] = 3 * memo[i-1][0];
                memo[i][1] = 3 * memo[i-1][1] + memo[i-1][0];
                memo[i][2] = 3 * memo[i-1][2] + memo[i-1][1];
                memo[i][3] = 3 * memo[i-1][3] + memo[i-1][2];
                break;
        }
        memo[i][0] %= MOD7;
        memo[i][1] %= MOD7;
        memo[i][2] %= MOD7;
        memo[i][3] %= MOD7;
    }
    cout << memo[N-1][3] << endl;
}
