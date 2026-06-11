#include <bits/stdc++.h>
using namespace std;
int main() {
    string a; 
    int minn = 214748364; 
    cin >> a;
    for (int i = 1; i < a.size(); i++) 
        if (a[i] != a[i - 1]) 
            minn = min(max(int(a.size()) - i, i), minn);
    if (minn < a.size()) printf("%d\n", minn); else printf("%d\n", a.size());
    return 0;
}