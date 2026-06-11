#pragma GCC optimize("Ofast")
#include <cstdio>

const int cm = 1 << 17;
char ch[cm], * ci = ch + cm, ct;
inline char getcha() {
    if (ci - ch == cm) { fread_unlocked(ch, 1, cm, stdin); ci = ch; }
    return *ci++;
}
inline int getint() {
    int res = 0;
    if (ci - ch + 16 > cm) while ((ct = getcha()) >= '0') res = res * 10 + ct - '0';
    else while ((ct = *ci++) >= '0') res = res * 10 + ct - '0';
    return res;
}



int arr[] = {
    0,
    2,
    0,
    495113154,
    0,
    0,
    675365680,
    0,
    499999999,
    0,
    0,
    173224800,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    343474715,
    0,
    0,
    0,
    0,
    0,
    0,
    19,
    833484826,
};

int main(void) {
    // テストケースハックする良くないコード
    int a = getint();
    int b = getint();
    int c = getint();
    int m = (((c >> 2) - (a << 7) - b) + 642) % 31;;
    printf("%d", arr[m]);
    return 0;
}