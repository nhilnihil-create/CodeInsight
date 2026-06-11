#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m, x, cnt = 0;
    cin >> n >> m >> x;
    vector<int> costs(m);
    for (int i=0; i<m; i++) cin >> costs[i];
    for (int i=0; i<m; i++){
        if (costs[i] < x) cnt++;
        else break;
    }
    cout << min(cnt, m-cnt) << endl;
    return 0;
}