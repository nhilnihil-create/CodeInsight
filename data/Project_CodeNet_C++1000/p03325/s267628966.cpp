#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] % 2 == 0)
        {
            res++;
            a[i] /= 2;
        }
    }

    cout << res << endl;
	return 0;
}
