#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    int i, w;
    char s[1005];

    while(scanf("%s%d", s, &w) == 2) {
        if(w == 1){
            cout << s;
        }
        else{
            cout << s[0];
            for(i = 1; s[i]; i++) {
                if((i+1)% w == 1){
                    printf("%c", s[i]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
