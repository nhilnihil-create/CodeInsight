#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M,X;
    cin >> N >> M >> X;
    vector<int>A(M);
    map<int,int>Map;
    for(int i = 0; i < M; i++) {
        cin >> A[i];
        Map[A[i]]++;
    }
    int ans = 1000000;
    int cnt = 0;
    for(int i = X; i < N; i++) {
        if(Map[i] > 0) {
            cnt++;
        }
    }
    ans = min(cnt,ans);
    cnt = 0;
    for(int i = X; i >= 0; i--) {
        if(Map[i] > 0) {
            cnt++;
        }
    }
    ans = min(cnt,ans);
    cout << ans << endl;
}
