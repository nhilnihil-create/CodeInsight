#include <cstdio>
#include <cstring>
using namespace std;

char s[10];

int main() {
    for(int i = 0; i < 3; i++) {
        scanf("%s", s);
        if(i == 0)
            printf("%c", s[0]);
        if(i == 1)
            printf("%c", s[1]);
        if(i == 2)
            printf("%c", s[2]);
    }
    printf("\n");
}