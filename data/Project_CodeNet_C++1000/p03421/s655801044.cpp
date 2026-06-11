#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if ((n - 1) / b <= a - 1 && a - 1 <= n - b) {
        if (a == 1) {
            for (int i = n; i > 0; i--) {
                if (i != n) cout << " ";
                cout << i;
            }
            cout << endl;
            return 0;
        }
        int ans[300030], idx = 0, front = 1;
        int k = (n - b) / (a - 1), l = (n - b) % (a - 1);
        for (int i = 0; i < a - 1; i++) {
            int end;
            if (l > 0) {
                end = front + k;
                l--;
            }
            else end = front + k - 1; 
            for (int j = end; j >= front; j--) {
                ans[idx] = j;
                idx++;
            }
            front = end + 1;
        }
        front = n;
        while (idx < n) {
            ans[idx] = front;
            idx++;
            front--;
        }
        for (int i = 0; i < n; i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        
    }
    else cout << -1 << endl;

}