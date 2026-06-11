#include<stdio.h>
#include<string.h>
char S[100001];

int main() {
    scanf(" %s", S);
    int n = strlen(S);
    int h = (int) ((n + 1) / 2);
    int t = h;
    while(t >= 1 && S[t - 1] == S[h - 1] && S[n - t] == S[h - 1]) t--;
    printf("%d\n", n - t);
    return 0;
}