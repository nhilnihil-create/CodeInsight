#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    stack<char> st;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (st.empty() || S[i] == st.top()) st.push(S[i]);
        else st.pop();
    }

    cout << N - st.size() << endl;
}