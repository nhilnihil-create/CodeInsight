#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    map<string, int> list;
    queue<int> que;
    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        if(!list.count(A.at(i))) {
            list[A.at(i)] = 0;
        }
        list.at(A.at(i))++;
    }
    int M = 0;
    cin >> M;
    vector<string> B(M);
    for(int i = 0; i < M; i++) {
        cin >> B.at(i);
        if(!list.count(B.at(i))) {
            list[B.at(i)] = 0;
        }
        list.at(B.at(i))--;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans,list.at(A.at(i)));
    }
    for(int i = 0; i < M; i++) {
        ans = max(ans,list.at(B.at(i)));
    }

    cout << ans << endl;

    return 0;
}