#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int mod = (A%2) + (B%2) + (C%2);

    int cnt = 0;
    if (mod == 3 || mod == 0) {

    }
    else {
        cnt++;
        int target = mod == 1 ? 1 : 0;
        if (mod == 1) {
            A += (A%2) == 0 ? 1 : 0;
            B += (B%2) == 0 ? 1 : 0;
            C += (C%2) == 0 ? 1 : 0;
        }
        else {
            A += (A%2) == 0 ? 0 : 1;
            B += (B%2) == 0 ? 0 : 1;
            C += (C%2) == 0 ? 0 : 1;
        }
    }

    int ma = max(max(A, B), C);
    cnt += (ma - A) / 2;
    cnt += (ma - B) / 2;
    cnt += (ma - C) / 2;

    put(cnt);

    return 0;
}