#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, K;
    cin >> N >> K;

    double ans = 0;
    double tmp_ans;
    int score;
    for ( int first_score=1; first_score<=N; first_score++ ) {
        score = first_score;
        tmp_ans = (double) 1 / N;
        while ( score < K ) {
            tmp_ans /= 2;
            score *= 2;
        }
        ans += tmp_ans;
    }

    printf("%.10lf\n", ans);
    return 0;
}
