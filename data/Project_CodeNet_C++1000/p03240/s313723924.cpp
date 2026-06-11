#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x[n], y[n], h[n];
    int xt, yt, ht;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> h[i];
        if(h[i] > 0) {
            xt = x[i], yt = y[i];
            ht = h[i];
        }
    }

    int cx, cy, H;
    for (cx = 0; cx <= 100; cx++)
    {
        for (cy = 0; cy <= 100; cy++)
        {
            H = ht + abs(xt - cx) + abs(yt - cy);
            bool ok = true;
            for (int i = 0; i < n; i++)
            {
                if(h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }

    }

	return 0;
}
