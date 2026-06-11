#include <bits/stdc++.h>
#define rep(i,n) for (int i = 1; i <= n; ++i)
using namespace std;

int main()
{
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> divisor_A(100), divisor_B(100);
    vector<int> ans(100);
    int cnt = 0;

    rep(i, A) {
        if (A % i == 0) {
            divisor_A.at(cnt) = i;
            cnt++;
        }
    }
    cnt = 0;

    rep(i, B) {
        if (B % i == 0) {
            divisor_B.at(cnt) = i;
            cnt++;
        }
    }

    cnt = 0;
    for (int i = 0; i < divisor_A.size(); i++) {
        for (int j = 0; j < divisor_B.size(); j++) {
            if (divisor_A.at(i) == divisor_B.at(j) && divisor_A.at(i) != 0) {
                ans.at(cnt) = divisor_A.at(i);
                cnt++;
            }  
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    cout << ans.at(K-1) << endl;
}