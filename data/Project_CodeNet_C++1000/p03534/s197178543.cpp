#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=1e5+50;
char s[maxn];
int cnt[maxn];

int main(){
    scanf("%s",s);
    int len=strlen(s);
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<len;i++){
        cnt[s[i]]++;
    }
    for (char i='a';i<='c';i++){
        for (char j='a';j<='c';j++){
            if (cnt[i]-cnt[j]>1){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}