#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {

    int n;
    cin >> n;
    vector<string> d(n);
    int top_b = 0, bottom_a =0, both = 0;
    for (int i = 0; i < n; ++i) {   

        cin >> d[i];
        bool tb = false, ba = false;

        // printf("input: %s\n", d[i].c_str());

        if (d[i][0] == 'B') {
            tb = true;
        }
        if (d[i][d[i].size()-1] == 'A') {
            ba = true;
        }

        // printf("bottom_a:%d,top_b%d\n", ba, tb);

        if (tb && ba) {
            both++;
        } else if (tb) {
            top_b++;
        } else if (ba) {
            bottom_a++;
        }
    }

    int ord = 0;
    for (auto& s: d) {
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == 'A' && s[i+1] == 'B') {
                ord++;
            }
        }
    }
    int comb = 0;
    if (both == 0) {
        comb = min(bottom_a, top_b);
    } else {
        if (bottom_a + top_b == 0) {
            comb = both - 1;
        } else {
            comb = both + min(bottom_a, top_b);
        }
    }

    cout << ord + comb << endl;

    return 0;
}