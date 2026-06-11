#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    map<int,int> mp;
    for(int i=1; i<=N; i++) {
        int tmp = i;
        for(int j=2; j<=N; j++) {
            while(tmp%j == 0) {
                tmp /= j;
                mp[j]++;
            }
        }
    }

    int cnt74 = 0;
    int cnt24 = 0;
    int cnt14 = 0;
    int cnt04 = 0;
    int cnt02 = 0;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        int val = itr->second;
        if(val >= 74) cnt74++;
        if(val >= 24) cnt24++;
        if(val >= 14) cnt14++;
        if(val >= 04) cnt04++;
        if(val >= 02) cnt02++;
    }

    int ans = 0;
    ans += cnt74;
    ans += cnt24 * (cnt02 - 1);
    ans += cnt14 * (cnt04 - 1);
    ans += cnt04 * (cnt04 - 1) / 2 * (cnt02 - 2);

    cout << ans << endl;
    return 0;
}
