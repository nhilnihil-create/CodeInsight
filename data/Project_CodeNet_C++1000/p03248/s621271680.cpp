#include <iostream>
#include <string>

using namespace std;

bool pal(std::string const& s) {
  return s == std::string(s.rbegin(), s.rend());
}

int main(void) {
    string s;
    cin >> s;
    int n = s.size();
    s = "0" + s;

    if(!pal(s) || s[1] == '0') {
        cout << -1 << endl;
    } else {
        int r = 1;
        for(int i=2; i<=n; i++) {
            cout << r << ' ' << i << endl;
            if(s[i-1] == '1') {
                r = i;
            }
        }
    }
    return 0;
}
