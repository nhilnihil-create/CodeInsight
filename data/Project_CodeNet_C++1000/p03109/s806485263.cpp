#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));

    if (y < 2019)
        cout << "Heisei" << endl;
    else if (y == 2019)
    {
        if (m < 5)
            cout << "Heisei" << endl;
        else
            cout << "TBD" << endl;
    }
    else
        cout << "TBD" << endl;
}
