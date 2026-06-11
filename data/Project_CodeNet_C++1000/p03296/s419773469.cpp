#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, ans = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for (int i = 0; i < N - 1; i++){
        if (A.at(i) == A.at(i + 1)){
            ans++;
            A.at(i + 1) = 10001;
        }
    }
    cout << ans << endl;
}

