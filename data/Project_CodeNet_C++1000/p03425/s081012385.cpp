#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    map<char, int64_t>d;
    for (int64_t i=0; i<N; i++) {
        string s;
        cin >> s;
        if (d.count(s[0]) > 0) {
            d[s[0]] = d[s[0]] + 1;
        } else {
            d[s[0]] = 1;
        }
    }

    int64_t initial_count = 0;
    int64_t initial_type_count = 0;
    for (auto c : d) {
        if (c.first == 'M' || c.first == 'A' || c.first == 'R' || c.first == 'C' || c.first == 'H') {
            initial_count += c.second;
            initial_type_count++;
        }
    }



    if (initial_type_count < 3) {
        cout << 0 << endl;
    } else {
        int64_t zentai_ = initial_count * (initial_count -1) * (initial_count -2) / 3 / 2;
        for (auto c : d)
        {
            if (c.first == 'M' || c.first == 'A' || c.first == 'R' || c.first == 'C' || c.first == 'H')
            {
                if (c.second >= 2)
                {
                    int64_t daburiwoerabukumiawase = c.second * (c.second - 1) / 2;
                    int64_t nokorino_initial_count = initial_count - c.second;
                    zentai_ = zentai_ - (daburiwoerabukumiawase * nokorino_initial_count);
                }

                if (c.second >= 3) {
                    int64_t three_use_count = c.second * (c.second -1) * (c.second - 2) / 3 / 2;
                    zentai_ = zentai_ - three_use_count;
                }
            }
        }

        cout << zentai_ << endl;
    }
    return 0;
}