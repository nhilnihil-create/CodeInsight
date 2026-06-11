#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N);
    REP(i, N) cin >> a[i];

    // dp_min[i]: 後ろから i 番目を Y が引いたときの |X_Y| の最小値
    // dp_max[i]: 後ろから i 番目を X が引いたときの |X-Y| の最大値
    vector<int> dp_min(N+1), dp_max(N+1);
    dp_min[1] = 1e+9;
    dp_max[1] = abs(a[N-1]-W);
    FOR(i, 2, N+1){
        dp_min[i] = abs(a[N-i]-a[N-1]);
        dp_max[i] = abs(a[N-i]-a[N-1]);
        FOR(j, 1, i){
            dp_min[i] = max(dp_min[i], dp_max[j]);
            dp_max[i] = min(dp_max[i], dp_min[j]);
        }
    }
    cout << *max_element(dp_max.begin(), dp_max.end()) << endl;

    return 0;
}