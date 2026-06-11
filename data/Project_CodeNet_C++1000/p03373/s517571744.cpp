#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
#define REP(i,n) for (int i=0;i<(n);++i)
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans =  0 * 2 * c + max(0, x - 0) * a + max(0, y - 0) * b;

    for(int i = 1; i <= 100000; ++i){
        int tmp = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
