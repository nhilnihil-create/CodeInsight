#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N;
int M=3;
int ans;
vector<int>A;

void dfs(vector<int> &B) {
    // 数列の長さが N に達したら打ち切り
    if (B.size() == N) {
        // 処理
        bool condition = false;
        for (int i=0; i<N; i++){
            if(B[i]%2 == 0)condition = true;
        }
        if (condition) ans++;
        return;
    }

    for (int v = 0; v < M; ++v) {
        int bi;
        if (v == 0)bi = A[B.size()]+1;
        else if (v == 1)bi = A[B.size()];
        else  bi = A[B.size()]-1;
        
        B.push_back(bi);
        dfs(B);
        B.pop_back();
    }
}


int main() {
    cin >> N;
    ans = 0;
    A.resize(N);
    for (int i=0; i<N; i++)cin >> A[i];
    
    vector<int>B;
    dfs(B);
    
    cout << ans << endl;
}