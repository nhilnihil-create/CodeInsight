#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> cnt(M);
    for(int i =0 ; i < N; i++){
        int K;
        cin >> K;
        for(int i = 0; i < K; i++){
            int a;
            cin >> a;
            a--;
            cnt[a]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        if(cnt[i] == N) ans++;
    }
    cout << ans << endl;
}