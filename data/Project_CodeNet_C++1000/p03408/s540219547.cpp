#include<iostream>
#include<map>
using namespace std;
int main(){
    int N, M;
    int ans = 0;
    cin >> N;
    string s[N];
    for(int i = 0; i < N; i++) cin >> s[i];
    cin >> M;
    string t[M];
    for(int i = 0; i < M; i++) cin >> t[i];

    map<string, int> money;
    for(int i = 0; i < N; i++) money[s[i]];
    for(int i = 0; i < M; i++) money[t[i]];

    for(auto p : money){
        auto k = p.first;
        for(int i = 0; i < N; i++){
            if(k == s[i]) money[k]++;
        }
        for(int i = 0; i < M; i++){
            if(k == t[i]) money[k]--;
        }
    }
    for(auto p : money){
        auto v = p.second;
        if(v > ans) ans = v;
    }
    cout << ans << endl;
}