#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int N;
    cin >> N;
    int A[2][N];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    int max_ans = -1;
    for(int i = 0; i < N; i++){
        int ans = 0;

        for(int j = 0; j <= i; j++){
            ans += A[0][j];
        }
        for(int j = i; j < N; j++){
            ans += A[1][j];
        }
        max_ans = max(max_ans, ans);
    }
    cout << max_ans << endl;
    
    return 0;
}