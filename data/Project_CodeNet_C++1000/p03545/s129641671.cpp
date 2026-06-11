#include <cstdio>
using namespace std;
int main() {
    int a, b, c, d;
    scanf("%1d%1d%1d%1d", &a, &b, &c, &d);
    int mult[] = {1, -1};
    char s[2] = {'+', '-'};
    int idx[3] = {};
    for (int i = 0; i < 8; i++) {
        idx[0] = (i & 0x1) > 0;
        idx[1] = (i & 0x2) > 0;
        idx[2] = (i & 0x4) > 0;
        if (a + b * mult[idx[0]] + c * mult[idx[1]] + d * mult[idx[2]] == 7) {
            printf("%d%c%d%c%d%c%d=7\n",a,s[idx[0]],b,s[idx[1]],c,s[idx[2]],d);
            return 0;
        }
    }
}


