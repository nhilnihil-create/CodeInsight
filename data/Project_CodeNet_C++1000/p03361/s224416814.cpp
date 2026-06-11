#include <bits/stdc++.h>
using namespace std;

int main() {

int h, w;
cin >> h >> w;

string defS = "";
for (int i = 0; i < w + 2; i++) defS = defS + ".";

vector<string> s(h + 2, defS);

for (int i = 1; i <= h; i++) {
    cin >> s.at(i);
    s.at(i) = "." + s.at(i) + ".";
}
string answer = "Yes";

for (int i = 1; i <= h; i++ ) {
    for (int j = 1; j <= w; j++) {
        if (s.at(i).at(j) == '#') {
            if (s.at(i - 1).at(j) == '.' && s.at(i).at(j - 1) == '.' && s.at(i + 1).at(j) == '.' && s.at(i).at(j + 1) =='.') {
                answer = "No";
                break;
            }
        }
    }
}

cout << answer << endl;

return 0;
}