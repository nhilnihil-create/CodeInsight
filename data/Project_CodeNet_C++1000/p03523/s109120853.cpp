#include <stdio.h>
#include <string.h>


int main () {
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    int ct=0;
    int no=0;
    int a=0;
    int yes=0;
    for (int i=0; i<len;i++) {
        //printf("%d ", i);
        if (ct==6) {
            no = 1;
            break;
        }

        if (ct==5 && s[i]=='A') ct++;
        else if (ct==5) {
            no = 1;
            break;
        }

        if (ct==4 && s[i]=='A' && a==0) {
            a++;
            continue;
        }
        else if (ct==4 && s[i]=='R') {
            yes=1;
            ct++;
            a=0;
        }
        else if (ct==4) {
            no = 1;
            break;
        }

        if (ct==3 && s[i]=='A' && a==0) {
            a++;
            continue;
        }
        else if (ct==3 && s[i]=='B') {
            ct++;
            a=0;
        }
        else if (ct==3) {
            no = 1;
            break;
        }

        if (ct==2 && s[i]=='H') {
            ct++;
            a=0;
        }
        else if (ct==2) {
            no = 1;
            break;
        }

        if (ct==1 && s[i]=='I') {
            ct++;
            a=0;
        }
        else if (ct==1) {
            no = 1;
            break;
        }

        if (ct==0 && s[i]=='A' && a==0) {
            a++;
            continue;
        }
        else if (ct==0 && s[i]=='K') {
            ct++;
            a=0;
        }
        else if (ct==0) {
            no=1;
            break;
        }

    }
    if (yes==1 && no==0) printf("YES\n");
    else printf("NO\n");
    return 0;
}