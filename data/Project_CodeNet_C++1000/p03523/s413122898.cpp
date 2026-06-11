#include <bits/stdc++.h>
using namespace std;

char s[55];

int subsq(const char *s, const char *t){
    int n = strlen(t);
    int m = strlen(s);
    for(int i = 0, j = 0; i < n; i++){
        if(s[j] == t[i]) j++;
        if(j == m) return 1;
    }
    return 0;
}

int main(){
    scanf("%s", s);
    if(subsq(s, "AKIHABARA") && subsq("KIHBR", s)) puts("YES");
    else puts("NO");
}