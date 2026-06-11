#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, K;
    string S;
    cin >> N >> K >> S;

    vector<int> nums;   /* 1-0-1-...-0-1 の個数の配列 */
    int         now = 1;
    int         cnt = 0;
    for ( int i = 0; i < N; i++ ) {
        if ( S.at(i) == now + '0' )
            cnt++;
        else {
            nums.push_back(cnt);
            cnt = 1;
            now = 1 - now;
        }
    }
    if ( cnt != 0 )
        nums.push_back(cnt);

    /* 1-0-1-...-0 だったら最後にダミーの0を置く */
    if ( nums.size() % 2 == 0 )
        nums.push_back(0);

    int ans = 0;
    int sum = 0;
    int left = 0, right = 0;

    for ( int i = 0; i < (int)nums.size(); i+= 2 ) {
        int nleft = i;
        int nright = min(i + 2 * K + 1, (int)nums.size());

        while ( nleft > left ) {
            sum -= nums.at(left);
            left++;
        }

        while ( nright > right ) {
            sum += nums.at(right);
            right++;
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}
