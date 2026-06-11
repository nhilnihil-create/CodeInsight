#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll , ll> PLL;
typedef long double ld;

#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define MOD 1000000007
#define PI 3.14159265
#define endl '\n'
#define MAX 200001


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int n = str.size();
    if (str[0] == '0' || str[n - 1] == '1') {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 1; i < n - 1; i++) {
        if (str[i] != str[n - i - 2]) {
            //cout << "what going on" << i << endl;
            cout << "-1" << endl;
            return 0;
        }
    }
    int s = 0;
    cout << "1 2" << endl;
    for (int i = 1; i < n - 1; i++) {
        cout << s + 1 << " " << i + 2 << endl;
        if (str[i] == '1') {
            s = i + 1;
        }
    }

    return 0;
}
