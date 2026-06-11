#include<iostream>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int dp[3001][3001];

int main() {
    string s, t;
    cin >> s >> t;

    for (int i=0; i < s.length(); i++)
        dp[i][0] = 0;
    for (int i=0; i < t.length(); i++)
        dp[0][i] = 0;

    for (int i=1; i <= s.length(); i++)
        for (int j=1; j <= t.length(); j++) {
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    char res[dp[s.length()][t.length()]+1] = {'\0'};
    int cur = dp[s.length()][t.length()];
    cur--;
    if (cur < 0) {
        cout<<endl;
        return 0;
    }
    int i = s.length(), j = t.length();
    while(1) {
        if(s[i-1] == t[j-1]) {
            res[cur--] = s[i-1];
            i--; j--;
            if (cur < 0)
                break;
        }
        else {
            if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    printf("%s\n", res);
    return 0;
}
