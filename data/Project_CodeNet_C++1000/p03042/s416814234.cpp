#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

char s[10];

bool mon(int x) {
    return 1 <= x && x <= 12;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%s", s);
    int x = (s[0] - '0') * 10 + s[1] - '0';
    int y = (s[2] - '0') * 10 + s[3] - '0';
    if (mon(x) && mon(y)) {
        printf("AMBIGUOUS");
    } else if (mon(x)) {
        printf("MMYY");
    } else if (mon(y)) {
        printf("YYMM");
    } else {
        printf("NA");
    }
    return 0;
}
