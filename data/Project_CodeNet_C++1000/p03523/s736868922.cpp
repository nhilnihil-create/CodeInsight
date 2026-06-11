#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
string AKB = "AKIHABARA";
vector<string> ans;

void rec(string str, int i) {
    if (i == 9) {
        ans.push_back(str);
        return;
    }
    else {
        if (AKB[i] == 'A') {
            rec(str, i+1);
            rec(str+'A', i+1);
        }
        else {
            rec(str+AKB[i], i+1);
        }
    }
    return;
}

int main() {
    cin >> S;

    rec("", 0);

    bool f = false;
    for (int i = 0; i < ans.size(); i++) {
        if (S == ans[i]) {
            f = true;
            break;
        }
    }

    cout << (f ? "YES" : "NO") << endl;

    return 0;
}
