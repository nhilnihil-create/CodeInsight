#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<vector<int64_t>> connect(N);
    for (int64_t i = 0; i < M; i++) {
        int64_t A, B;
        cin >> A >> B;
        A--; B--;
        connect[A].push_back(B);
        connect[B].push_back(A);
    }

    enum {
        BLACK, WHITE, UNDEFINED
    };
    vector<int64_t> color(N, UNDEFINED);

    stack<int64_t> st;
    color[0] = BLACK;
    st.push(0);
    while (!st.empty()) {
        int64_t top = st.top();
        st.pop();

        int64_t next_color = (color[top] == BLACK ? WHITE : BLACK);

        for (int64_t next_node : connect[top]) {
            if (color[next_node] == UNDEFINED) {
                //塗られていなかったら塗る
                color[next_node] = next_color;
                st.push(next_node);
            } else if (color[next_node] != next_color) {
                //矛盾する-> 2部グラフにならない
                //全辺が張れる
                cout << N * (N - 1) / 2 - M << endl;
                return 0;
            }
        }
    }

    int64_t black_num = 0;
    for (int64_t i = 0; i < N; i++) {
        black_num += (color[i] == BLACK);
    }

    cout << black_num * (N - black_num) - M << endl;
}