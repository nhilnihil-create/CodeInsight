#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;   cin >> N >> K;
    int *a = new int[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<bool> dp1(K+1, false);   //今から先手側がひくときに残りi個だった場合の勝ち負け
    dp1[a[0]] = true;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= a[j] && !dp1[i-a[j]])
                dp1[i] = true;
        }
    }

    if (dp1[K])
        cout << "First" << endl;
    else 
        cout << "Second" << endl;
    return 0;
}