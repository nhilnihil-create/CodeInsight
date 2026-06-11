#include <iostream>

using namespace std;

int main (void) {
    long long N, M;
    cin >> N >> M;

    long long ans;
    if ( N == 1 && M == 1 )
        ans = 1;
    else if ( N == 1 )
        ans = M - 2;
    else if ( M == 1 )
        ans = N - 2;
    else if ( N == 2 || M == 2 )
        ans = 0;
    else {
        /*
         * どちらも 1 でないとき、
         * 四隅 : 表
         * 内部 : 裏
         * 辺上 : 表
         */
        ans = (N - 2) * (M - 2);
    }
    cout << ans << endl;
    return 0;
}
