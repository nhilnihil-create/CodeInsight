#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[4];
    scanf("%s", s);
    int n = strlen(s);
    if (n == 2) {
        printf("%s\n", s);
    }
    else if (n == 3) {
        for (int i = n - 1; i >= 0; --i) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}
