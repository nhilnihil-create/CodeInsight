#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    int INF = 1e9;
    cin >> N;
    vector<int> P(N); 
    for(int i = 0; i < N; i++) cin >> P[i];
    vector<int> cnt(N, INF);
    for(int i = 0; i < N; i++){
        if(P[i] - 2 >= 0 && cnt[P[i] - 2] != INF) cnt[P[i] - 1] = cnt[P[i] - 2] + 1;
        else if(cnt[P[i] - 1] == INF) cnt[P[i] - 1] = 1;
    }
    int mx = 0;
    for(int i = 0; i < N; i++) mx = max(mx, cnt[i]);
    cout << N - mx << endl;
}