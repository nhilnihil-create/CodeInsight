#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, K, buf, ans = 0;
    cin >> N >> M;
    unordered_map<int,int> mp;
    for(int i = 1; i <= N; ++i){
        cin >> K;
        for(int j = 1; j <= K; ++j){
            cin >> buf;
            ++mp[buf];
        }
    }
    for(int i = 1; i <= M; ++i){
        if(mp[i] == N) ++ans;
    }
    cout << ans << endl;
    return 0;
}