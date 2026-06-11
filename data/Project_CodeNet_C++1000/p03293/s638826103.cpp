#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e6+7;
char s[N],t[N];
int main(){
    scanf("%s%s",s,t);
    int n=strlen(s);
    for(int i=0;i<n;i++){
        char c=s[n-1];
        for(int j=n-1;j>=1;j--) s[j]=s[j-1];
        s[0]=c;
        if(strcmp(s,t)==0){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}
