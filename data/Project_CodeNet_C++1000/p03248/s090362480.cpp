#include <bits/stdc++.h>

#define N 1000010 

using namespace std;

char s[N];

queue <int> q;

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    if (s[1] == '0' || s[n] == '1') {
        puts("-1");
        return 0;
    }
    for (int i = 1; i < n; i ++ ) {
        if (s[i] != s[n - i]) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == '1') {
            q.push(i);
        }
    }
    q.push(n);
    for (int i = 1; i < n; i ++ ) {
        if (i == q.front()) {
            q.pop();
        }
        printf("%d %d\n", i, q.front());
    }
    return 0;
}