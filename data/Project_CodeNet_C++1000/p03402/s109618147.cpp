#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=3000;
typedef unsigned long long ull;
const int maxn=1e5+5;
typedef long long ll;
int ans[200][200];
int main(){
    memset(ans,0,sizeof(ans));
    int a,b;
    scanf("%d%d",&a,&b);
    printf("100 100\n");
    int i,j;
    for (i=0;i<100;i++){
    for (j=0;j<100;j++){
        if (i%2)
            ans[i][j]=0;
        else {
            if (a==1)
                ans[i][j]=0;
            else {
                if (j%2==0)
                {
                    ans[i][j]=1;
                    a--;
                }
                else
                    ans[i][j]=0;
            }
        }
        }
            if (a==1)
            break;
    }
    i++;
    if (i%2){
        for (j=0;j<100;j++)
            ans[i][j]=0;
        i++;
    }
        for (j=0;j<100;j++)
            ans[i][j]=1;
        i++;
    b--;
    for (;i<100;i++)
        for (j=0;j<100;j++){
            if (i%2==0)
                ans[i][j]=1;
            else {
                if (b==0)
                    ans[i][j]=1;
                else {
                    if (j%2==0)
                    {
                        ans[i][j]=0;
                        b--;
                    }
                    else
                        ans[i][j]=1;
                }
            }
        }
    for (i=0;i<100;i++){
        for (j=0;j<100;j++)
            if (ans[i][j])
                printf(".");
            else
                printf("#");
        printf("\n");
    }
}
