#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int64_t D, G;
    cin >> D >> G;
    vector<pair<int, pair<int, int>>> pairs(D);
    rep(i, D){
        int p, c;
        cin >> p >> c;
        pairs.at(i) = make_pair(100 * (i + 1), make_pair(p, c));
    }
    sort(pairs.begin(), pairs.end());
    reverse(pairs.begin(), pairs.end());

    int ans = 1001;
    for (int bit = 0; bit < (1 << 10); bit++){
        int count = 0;
        int64_t sum = 0;
        rep(i, D){
            if (bit & (1 << i)){
                int tmp_count = pairs.at(i).second.first;
                count += tmp_count;
                sum += pairs.at(i).first * tmp_count;
                sum += pairs.at(i).second.second;
            }
        }
        if (sum < G){
            rep(i, D){
                if (!(bit & (1 << i))){
                    int tmp_count = pairs.at(i).second.first;
                    tmp_count--;
                    if (sum + tmp_count * pairs.at(i).first < G){
                        count += tmp_count;
                        sum += tmp_count * pairs.at(i).first;
                    }
                    else{
                        tmp_count = (G - sum + pairs.at(i).first - 1) / pairs.at(i).first;
                        count += tmp_count;
                        sum += pairs.at(i).first * tmp_count;
                        break;
                    }
                }
            }
        }
        if (sum >= G) ans = min(ans, count);
    }
    cout << ans << endl;
}
