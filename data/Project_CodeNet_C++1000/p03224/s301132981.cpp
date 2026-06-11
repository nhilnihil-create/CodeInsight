#include <iostream>
#include <fstream>
#include <vector>

#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    int k = -1;
    for (int i = 1; i <= n + 1; i++)
        if ((long long)i * (i - 1) / 2 == n){
            k = i - 1;
            break;
        }
    if (k == -1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<vector<int> > x(k + 1);
    FOR (i, k + 1)
        x[i].resize(k);
    int cur_i = 0, cur_j = 0;
    int num = 1;
    while (num <= n){
        for (int i = cur_i + 1; i < k + 1; i++)
            x[i][cur_j] = num + i - cur_i - 1;
        for (int j = cur_j; j < k; j++)
            x[cur_i][j] = num + j - cur_j;
        num += k - cur_i;
        cur_i++;
        cur_j++;
    }
    cout << x.size() << '\n';
    FOR (i, x.size()){
        cout << x[i].size() << ' ';
        FOR (j, x[i].size())
            cout << x[i][j] << ' ';
        cout << '\n';
    }
}