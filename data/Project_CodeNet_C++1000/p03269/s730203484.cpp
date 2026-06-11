#include <iostream>
#include <cstring>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;

int main(void){
    int l, b = 1, cnt = 0;
    vector<int> u, v, w;
    cin >> l;
    
    while (b <= l) {
        b *= 2;  cnt++;
    }
    for (int i = 1; i <= cnt - 1; i++) {
        u.push_back(i);  v.push_back(i + 1);  w.push_back(pow(2, i - 1));
        u.push_back(i);  v.push_back(i + 1);  w.push_back(0);
    }
    l -= b / 2;
    int n = cnt, k = b / 2;
    
    while (l != 0) {
        cnt = 0;
        b = 1;
        while (b <= l) {
            b *= 2;  cnt++;
        }
        u.push_back(cnt);  v.push_back(n);  w.push_back(k);
        k += b / 2;
        l -= b / 2;
    }
    
    
    cout << n << " " << u.size() << endl;
    for (int i = 0; i < u.size(); i++) cout << u[i] << " " << v[i] << " " << w[i] << endl;
}
