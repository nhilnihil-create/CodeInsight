#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string, int> T;
    string S;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S;
        T[S]++;
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> S;
        T[S]--;
    }
    int ans = 0;
    map<string, int>::iterator it;
    for(it = T.begin(); it != T.end(); it++){
        pair<string, int> item = *it;
        ans = max(ans, item.second);
    }
    cout << ans << endl;
    return 0;
}