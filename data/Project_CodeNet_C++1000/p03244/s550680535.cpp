#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

// cant imp

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, v;
    cin >> n;
    vector<int> ecnt(100001, 0), ocnt(100001, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        if (i % 2 == 0) ecnt[v]++;
        else ocnt[v]++;
    }

    int max_ecnt = 0, max_ocnt = 0;
    int max_e = 0, max_o = 0;
    for (int i = 0; i < 100001; i++) {
        if (max_ecnt < ecnt[i]) {
            max_ecnt = ecnt[i];
            max_e = i;
        }
        if (max_ocnt < ocnt[i]) {
            max_ocnt = ocnt[i];
            max_o = i;
        }
    }

    int ans;
    if (max_o == max_e) {
        sort(ecnt.begin(), ecnt.end(), greater<int>());
        sort(ocnt.begin(), ocnt.end(), greater<int>());
        int t1 = n - max_ecnt - ocnt[1];
        int t2 = n - ecnt[1] - max_ocnt;
        ans = min(t1, t2);
    } else {
        ans = n - max_ocnt - max_ecnt;
    }

    cout << ans << endl;
}