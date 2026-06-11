#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int match(int a){
    if(a == 1) return 2;
    else if(a == 2) return 5;
    else if(a == 3) return 5;
    else if(a == 4) return 4;
    else if(a == 5) return 5;
    else if(a == 6) return 6;
    else if(a == 7) return 3;
    else if(a == 8) return 7;
    else return 6;
}

int main(){
    int N, M;
    cin >> N >> M;
    int A[M];
    for(int i=0; i<M; i++) cin >> A[i];
    sort(A, A + M);
    string dp[N+10];
    fill(dp, dp + N + 10, "?");
    dp[0] = "";
    for(int i=0; i<N; i++){
        for(int a : A){
            if(dp[i] != "?") {
                if(dp[i + match(a)] == "?" || dp[i + match(a)].length() < dp[i].length() + 1 || (dp[i +match(a)].length() == dp[i].length() + 1 && dp[i + match(a)] < dp[i] + to_string(a))) dp[i + match(a)] = dp[i] + to_string(a);
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}