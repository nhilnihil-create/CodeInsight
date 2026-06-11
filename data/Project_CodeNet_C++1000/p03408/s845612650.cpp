#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int N;
    cin >> N;

    vector<string> vec_s(N);
    for (int i = 0; i < N; i++) {
        cin >> vec_s[i];
    }

    int M;
    cin >> M;

    vector<string> vec_m(M);
    for (int i = 0; i < M; i++) {
        cin >> vec_m[i];
    }
    int ans = 0;
    string target;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        target = vec_s[i];
        for (int j = 0; j < N; j++) {
            if (target == vec_s[j]) 
                temp += 1;
        }
        for (int k = 0; k < M; k++) {
            if (target == vec_m[k]) 
                temp -= 1;
            
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}