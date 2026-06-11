#include <bits/stdc++.h>
#include <chrono>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9
#define f first
#define s second

typedef long long ll;

using namespace std;

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int a, b, k;

    cin >> a >> b >> k;

    for (int i = 0; i < k; i++) {

        if (i%2) {

            int z = b/2;
            b-=(b%2), b-=z, a+=z;
        } else {

            int z = a/2;
            a-=(a%2), a-=z, b+=z;
        }
    }

    cout << a << " " << b;

    return 0;
}
