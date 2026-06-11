#include <bits/stdc++.h>
using namespace std;

/*
left to rightにforループでWの人を数えて各場所での人の数を保存
right to leftにEの人を同じく数える。
各時点についてそれぞれの配列から向きを変える人数を計算し、maxを保存しておく。O(N)
*/

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> left_to_right(N, 0);
    vector<int> right_to_left(N, 0);

    int n_w = 0;
    for (int i = 0; i < N; i++)
    {
        left_to_right[i] = n_w;
        if (S[i] == 'W')
            n_w++;
    }

    int n_e = 0;
    for (int i = N - 1; i >= 0; i--) {
        right_to_left[i] = n_e;
        if (S[i] == 'E')
            n_e++;
    }

    int minv = 1e9;
    for (int i = 0; i < N; i++)
    {
        minv = min(minv, left_to_right[i] + right_to_left[i]);
    }
    cout << minv << endl;
}