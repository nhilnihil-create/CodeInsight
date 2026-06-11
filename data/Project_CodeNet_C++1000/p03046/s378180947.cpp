/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.19 01:54:54
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int m,k;cin >> m >> k;
    if ((1<<m)-1<k) {
        puts("-1");
        return 0;
    }
    if (m == 1 && k == 1) {
        puts("-1");
        return 0;
    }
    else if (m == 1 && k == 0) {
        cout << "1 1 0 0" << endl;
        return 0;
    }
    for (int i = 0; i < 1<<m; i++) {
        if (i == k)continue;
        cout << i << " ";
    }
    cout << k << " ";
    for (int i = (1<<m)-1; i >= 0; i--) {
        if (i == k) continue;
        cout << i << " ";
    }
    cout << k << endl;
    return 0;
}