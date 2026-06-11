#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,
        37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    vector<int> num(101, 0);
    if (N <= 9){
        cout << 0 << endl;
        return 0;
    }
    rep(i, 2, N + 1){
        int p = i;
        rep(j, 0, 25){
            if (p == 1) break;
            if (p % prime.at(j) == 0){
                p /= prime.at(j);
                num.at(prime.at(j))++;
                j--;
            }
        }
    }
    int count_2 = 0, count_4 = 0, count_14 = 0, count_24 = 0, count_74 = 0;
    rep(i, 0, 101){
        //cout << i << " " << num.at(i) << endl;
        if (num.at(i) >= 2) count_2++;
        if (num.at(i) >= 4) count_4++;
        if (num.at(i) >= 14) count_14++;
        if (num.at(i) >= 24) count_24++;
        if (num.at(i) >= 74) count_74++;
    }
    //cout << count_2 << " " << count_4 << " " << count_14 << " " << count_24 << endl;
    int ans = count_24 * (count_2 - 1) + count_14 * (count_4 - 1) + count_4 * (count_4 - 1) * (count_2 - 2) / 2 + count_74;
    cout << ans << endl;
}