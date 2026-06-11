#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
    cin >> s;
    vector<string> t{"KIH", "B", "R"};
    for (int bit = 0; bit < (1<<4); ++bit) {
        string target = "";
        for (int i = 0; i < 4; ++i) {
            if(bit & (1 << i)) {
                target += "A";
            }
            if(i < 3) target += t[i];
        }
        if(s == target) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
