#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int LIM = 200000;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> backet(LIM+1, 0);
    for(int i = 0; i < n; i++) backet[a[i]]++;

    sort(backet.begin(), backet.end(), greater<int>());

    int ans = 0;
    for(int i = k; i <= LIM; i++) ans += backet[i];

    cout << ans << endl;
    return 0;
}