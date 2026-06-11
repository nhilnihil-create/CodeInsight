#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++) cin >> x[i];

    sort(x.begin(), x.end());
    vector<int> diff;
    for(int i = 1; i < m; i++){
        diff.push_back(x[i]-x[i-1]);
    }

    sort(diff.begin(), diff.end());
    int ans = 0;
    for(int i = 0; i < m-n; i++) ans += diff[i];
    cout << ans << endl;
    return 0;
}