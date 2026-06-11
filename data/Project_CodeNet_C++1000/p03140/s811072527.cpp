#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

int main(){
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(A[i] == B[i] && A[i] == C[i]){
            continue;
        }else if(A[i] == B[i] || A[i] == C[i] || B[i] == C[i]){
            cnt++;
        }else{
            cnt += 2;
        }
    }
    cout << cnt << endl;
    return 0;
}
