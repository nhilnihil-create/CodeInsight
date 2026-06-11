/*Lucky_Glass*/
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char str[20];scanf("%s",str);
    int cnt=0;
    for(int i=0;i<strlen(str);i++) cnt+=str[i]=='o';
    if(cnt+15-strlen(str)>=8) printf("YES\n");
    else printf("NO\n");
    return 0;
}
