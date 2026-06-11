#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;
char s[N];
int cnt[5];

int main() {
    scanf("%s",s);
    int n = strlen(s);

    if(n==3) {
        set<char> st;
        for(int i=0; i<n; i++) st.insert(s[i]);
        if(st.size()==2)
            puts("NO");
        else puts("YES");
        return 0;
    }
    for(int i=0; i<n; i++) {
        cnt[s[i]-'a']++;
    }
    sort(cnt,cnt+3);
    if(cnt[2]-cnt[0] > 1) {
        puts("NO");
    } else {
        puts("YES");
    }


}


