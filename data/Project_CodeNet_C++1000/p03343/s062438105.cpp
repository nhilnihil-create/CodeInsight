#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 2005, INF = 1e9 + 5;
int a[N], b[N], c[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int ans = INF;

    for (int h = 0; h < n; h++) {

        for (int i = 0; i < n; i++) {
            c[i] = (a[i] < a[h]);
        }

        // if (k == 0) {
        //     for (int i = 0; i < n; i++)
        //         cout << c[i];
        //     cout << "\n";
        // } 

        int l = 0, r = INF;
        while (r - l > 1) {
            int p = (l + r) >> 1;

            for (int i = 0; i < n; i++) {
                b[i] = (a[i] <= p);
            }

            // if (p == 5 && h == 3) {
            //     for (int i = 0; i < n; i++) {
            //         cout << b[i];
            //     }
            //     cout << "\n";
            //     for (int i = 0; i < n; i++) {
            //         cout << c[i];
            //     }
            //     cout << "\n";
            // }

            fill(used, used + n, 0);

            int z = 0, cq = 0, y = 0, ct = k;
            for (int i = 0, j = k - 1; j < n; j++, ct++) {

                // if (p == 623690081 && a[h] == 211047202) {
                //     cout << i << " " << j << " " << ct << "\n";
                // }


                while (ct > k) {
                    ct -= !used[i];
                    i++;
                }

                if (ct < k)
                    break;

                y = max(i, y);
                z = max(i, z);

                while (y < n && c[y] == 0)
                    y++;

                if (y <= j)
                    continue;

                while (true) {
                    while (z < n && b[z] == 0)
                        z++;
                    if (z > j)
                        break;
                    used[z] = true;
                    j++;
                    cq++;
                    z++;
                    if (j >= n || y <= j)
                        break;
                }
            }

            if (cq >= q) {
                r = p;
            }
            else {
                l = p;
            }
        }

        
        if (r != INF) {
            // cout << r << " " << a[h] << " " << r - a[h] << "\n";
            ans = min(ans, r - a[h]);
        }
    }

    cout << ans;

    return 0;   
}