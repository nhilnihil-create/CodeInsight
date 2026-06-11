#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>

#define LR_L 0
#define LR_R 1
using namespace std;

int main(void) {
    int n,a,b;
    multiset<int> mr,ml;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a >> b;//L R
        ml.insert(a);
        mr.insert(b);
    }
    ml.insert(0);
    mr.insert(0);
    long long res = 0;
    auto itr_l = ml.rbegin();
    auto itr_r = mr.begin();
    while(*itr_l - *itr_r > 0) {
        res = res + (*itr_l - *itr_r);
        itr_r++;
        itr_l++;
    }
    cout << res * 2 << endl;
    return 0;
}
