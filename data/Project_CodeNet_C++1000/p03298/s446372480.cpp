#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <deque>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<string, string> ps;


map<ps, ll>dict;
ll ans;

int main()
{
    char c;
    string s, t;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        s += c;
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        t += c;
    }

    for (int i = 0; i < (1 << n); i++) {
        int tmp = i;
        
        string red, blue;

        for (int j = n - 1; j >= 0; j--) {
            if (tmp & 1) {
                red.insert(red.begin(), t[j]);
            }
            else {
                blue += t[j];
            }

            tmp = tmp >> 1;
        }

        dict[ps(red, blue)]++;
    }

    for (int i = 0; i < (1 << n); i++) {
        int tmp = i;
        
        string red, blue;

        for (int j = n - 1; j >= 0; j--) {
            if (tmp & 1) {
                red.insert(red.begin(), s[j]);
                //red += s[j];
            }
            else {
                blue += s[j];
                //blue.insert(blue.begin(), s[j]);
            }
            
            tmp = tmp >> 1;
        }

        if (dict.count(ps(blue, red))) {
            ans += dict[ps(blue, red)];
        }
    }

    cout << ans << endl;

    return 0;
}
