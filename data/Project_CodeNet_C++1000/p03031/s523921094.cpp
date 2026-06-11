#include <bits/stdc++.h>
using namespace std;
// for(long long i = 0;i < num; i++){}
int main() {
    //
    int n, m;
    int cnt = 0;

    cin >> n >> m;

    vector<vector<int>> vec(m);
    vector<int> power(m);

    for (int i = 0; i < m; i++) {
        int x, tmp;
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> tmp;
            tmp--;
            vec.at(i).push_back(tmp);
        }
    }

    for (int i = 0; i < m; i++) cin >> power.at(i);

    for (int bit = 0; bit < (1 << n); bit++) {
        bool chk = true;

        for (int i = 0; i < m; i++) {
            int tmpCnt = 0;
            //for (int j = 0; j < vec.at(i).size(); j++) {
                for(auto j : vec[i]){
                if (bit & (1 << j)) tmpCnt++;
            }

            if (tmpCnt % 2 != power.at(i)) chk = false;
        }

        if (chk == true) cnt++;
    }

    cout << cnt;
    //
}
