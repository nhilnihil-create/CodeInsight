#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int N, C;

int s[MAXN], t[MAXN], c[MAXN];
int needed[MAXN * 2], prefix[MAXN * 2];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; ++i){
        cin >> s[i] >> t[i] >> c[i];
    }
    memset(needed, 0, sizeof needed);
    for (int i = 1; i <= C; ++i){
        memset(prefix, 0, sizeof prefix);
        for (int j = 0; j < N; ++j){
            if (c[j] == i){
                prefix[s[j] * 2 - 1]++;
                prefix[t[j] * 2]--;
            }
        }
        for (int j = 1; j < MAXN * 2; ++j){
            prefix[j] += prefix[j-1];
        }
        for (int j = 0; j < MAXN * 2; ++j){
            if (prefix[j]) needed[j]++;
        }
    }
    int answer = 0;
    for (int i = 0; i < MAXN * 2; ++i){
        answer = max(answer, needed[i]);
    }
    cout << answer << endl;
    return 0;
}