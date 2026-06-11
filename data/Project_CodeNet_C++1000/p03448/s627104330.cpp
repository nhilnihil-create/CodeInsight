#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int x;
    cin >> x;

    int count = 0;
    rep(i, a + 1)
    {
        int a_ = i * 500;
        rep(j, b + 1)
        {
            int b_ = j * 100;
            //cout << "b__ : " << b__ << endl;

            rep(k, c + 1)
            {
                int c_ = k * 50;
                //cout << "c__ : " << c__ << endl;

                if (a_ + b_ + c_ == x)
                {
                    count++;
                    break;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}