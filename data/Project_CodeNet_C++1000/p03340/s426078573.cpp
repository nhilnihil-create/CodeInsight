#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

int main() {
    int64_t N, right = 0, sum = 0, ans = 0;
    cin >> N;
    vector<int64_t> A(N);
    for (int64_t i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    for (int64_t left = 0; left < N; left++) {

        while(right < N && sum + A.at(right) == (sum ^ A.at(right))){
            sum += A.at(right);
            right++;
        }
        
        ans += right - left;
        if (right == left) {
            right++;
        }
        else {
            sum -= A.at(left);
        }
    }
    cout << ans << endl;
}
