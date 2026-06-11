#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }
    ans = (n - 1) / (k - 1);
    if((n - 1) % (k - 1) != 0) ans++;
    cout << ans << endl;
    return 0;
}