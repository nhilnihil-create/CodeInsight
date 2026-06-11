#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2e5;
const int INF = (int) 1e9;

int sp[MAXN + 1][26];

string str;

unordered_map <int, int> dp;

inline int check(int x) {
    if(dp[x] == 0) {
       if(x == 0)
         return 0;
       return INF;
    }
    return dp[x];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> str;
    int n = str.size();
    str = " " + str;
    for(i = 1; i <= n; i++) {
       for(j = 0; j < 26; j++)
          sp[i][j] = sp[i - 1][j];
       sp[i][str[i] - 'a']++;
       sp[i][str[i] - 'a'] %= 2;
    }
    int ans = MAXN + 1;
    for(i = 1; i <= n; i++) {
       int cnf = 0;
       for(j = 0; j < 26; j++)
           cnf += (1 << j) * sp[i][j];
       int val = check(cnf);
       for(j = 0; j < 26; j++)
           val = min(val, check(cnf ^ (1 << j)) + 1);
       dp[cnf] = val;
     //  printf("%d\n" ,val);
       if(i == n) {
            if(val == 0)
               val = 1;
            cout << val;
            return 0;
       }
    }
    //cin.close();
    //cout.close();
    return 0;
}

