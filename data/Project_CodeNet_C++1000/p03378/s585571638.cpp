#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, X, buf;
    cin >> N >> M >> X;
    vector<bool> A(N+1, false);
    for(int i = 1; i <= M; ++i){
        cin >> buf;
        A[buf] = true;
    }
    buf = 0;
    for(int i = X; i > 0; --i){
        if(A[i]) ++buf;
    }
    int ans = buf;
    buf = 0;
    for(int i = X; i < N; ++i){
        if(A[i]) ++buf;
    }
    ans = min(ans, buf);
    cout << ans << endl;
}