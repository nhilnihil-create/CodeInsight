#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> P(n);
    copy_n(istream_iterator<int>(cin), n, P.begin());

    vector<int> idx(n + 1);
    for (int i = 0; i < n; i++)
        idx[P[i]] = i;

    int cnt = 0, ma = 0, prev = -1;
    for (int i = 1; i <= n; i++){
        if (prev < idx[i]){
            cnt++;
        } else {
            cnt = 1;
        }
        ma = max(ma, cnt);
        prev = idx[i];
    }

    cout << n - ma << endl;
}