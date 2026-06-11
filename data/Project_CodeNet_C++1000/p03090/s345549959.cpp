#include <iostream>
using namespace std;
int n;
int ans[10010][2],tot;
int main() {
    scanf("%d",&n);
    if(n%2) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                if(i!=j&&(n-i)!=j)
                    ans[++tot][0]=i,ans[tot][1]=j;
        printf("%d\n",tot);
        for(int i=1;i<=tot;i++)
            printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    else {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                if(i!=j&&(n-i+1)!=j)
                    ans[++tot][0]=i,ans[tot][1]=j;
        printf("%d\n",tot);
        for(int i=1;i<=tot;i++)
            printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}