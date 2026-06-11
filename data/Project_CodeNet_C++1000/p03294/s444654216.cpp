#include<iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            res = res + m - 1;
        }
        cout << res << endl;
    }
    return 0;
}
