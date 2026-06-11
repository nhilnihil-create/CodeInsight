#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, z, w;
    cin >> n >> z >> w;

    if (n == 1){
        int y;
        cin >> y;
        cout << abs(w - y) << endl;
        return 0;
    }

    int gomi;
    for (int i = 0; i < n - 2; i++)
        cin >> gomi;
    int x, y;
    cin >> x >> y;

    cout << max(abs(x - y), abs(y - w)) << endl;
}
