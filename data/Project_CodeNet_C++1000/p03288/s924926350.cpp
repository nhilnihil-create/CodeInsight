#include<cstdio>

using namespace std;

int main(){
    int r;
    scanf("%d", &r);
    if (r < 1200) puts("ABC");
    else if (r < 2800) puts("ARC");
    else puts("AGC");
}