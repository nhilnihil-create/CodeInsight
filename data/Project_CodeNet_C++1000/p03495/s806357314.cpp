#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;

    map<int, int> A;
    int c;
    for (int i = 0; i < N; i++)
    {
        /* code */
        cin >> c;
        if (A.count(c))
            A.at(c) += 1;
        else
        {
            A[c] = 1;
        }
    }


    int cnt = 0;
    vector<int> B;
    for (auto i = A.begin(); i != A.end(); i++)
    {
        // cout << i->second << endl;
        B.push_back(i->second);
    }
    sort(B.begin(), B.end());

    if (B.size() <= K)
        cout << 0 << endl;
    else {
        for (int i = 0; i < B.size() - K; i++)
        {
            cnt += B[i];
        }
        cout << cnt << endl;
    }
}