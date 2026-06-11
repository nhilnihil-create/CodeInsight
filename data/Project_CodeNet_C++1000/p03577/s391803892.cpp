#include <cstdio>
#include <cstring>

int main(){
    char in[1000000];
    scanf("%s",in);
    int l=strlen(in),i;
    for(i=0;i+8<l;i++)putchar(in[i]);
    putchar('\n');
    return 0;
}