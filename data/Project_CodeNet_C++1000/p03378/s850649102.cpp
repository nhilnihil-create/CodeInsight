#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    int n,m,x;
    int a[100];
    int l = 0;
    int r = 0;

    cin >> n >> m >> x;
    for(int i = 0; i < m; i ++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++){
        if(x > a[i]) l ++;
        else r ++;
    }
    if(l > r) cout << r;
    else cout << l;
    return 0;
}