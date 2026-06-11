#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    char s[4];
    scanf("%s",s);
    x=(s[0]-'0')*10+s[1]-'0';
    y=(s[2]-'0')*10+s[3]-'0';
    if (x>0 && x<13 && y>0 && y<13)    printf("AMBIGUOUS\n");
    else if (x>0 && x<13)    printf("MMYY\n");
    else if (y>0 && y<13)    printf("YYMM\n");
    else printf("NA\n");
    return 0;
}
