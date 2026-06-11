#include <bits/stdc++.h>
using namespace std;

string s;
string ans;

void Backtrack(int i, int total) {
    if (i==4) {
        if (total==7) {
            for (int j=0; j<ans.size(); ++j) {
                cout << ans[j];
            }

            cout << "=7";

            exit(0);
        }
        else {
            return;
        }
    }


    total+=(s[i]-'0');
    ans+='+';
    ans+=s[i];
    Backtrack(i+1, total);
    total-=(s[i]-'0');
    ans.pop_back();
    ans.pop_back();

    total-=(s[i]-'0');
    ans+='-';
    ans+=s[i];
    Backtrack(i+1, total);
    total+=(s[i]-'0');
    ans.pop_back();
    ans.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    ans+=s[0];
    Backtrack(1, s[0]-'0');

    return 0;
}
