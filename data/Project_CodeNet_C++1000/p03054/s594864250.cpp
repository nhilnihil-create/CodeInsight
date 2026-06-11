#include<bits/stdc++.h>
using namespace std;
const bool debug =0;

inline void read(int &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}

inline void write(int x){
    static const int maxlen=100;
    static char s[maxlen];
    if (x<0) {   putchar('-'); x=-x;}
    if(!x){ putchar('0'); return; }
    int len=0; for(;x;x/=10) s[len++]=x % 10+'0';
    for(int i=len-1;i>=0;--i) putchar(s[i]);
}


const int MAXN = 3e5+100;

int h,w,n;
char s[ MAXN ] ,t[ MAXN ];

int a[ MAXN ],b[ MAXN ];
int org_x,org_y;

bool doit(int org,int lim){
int l=1,r=lim;
for (int i=n;i>=1;i--)
{
    if ( a[i]==-1 )
        l++;

    if ( a[i]==1 )
        r--;

    if ( l>r )
        return 1;

    if ( b[i-1]==-1 )
    {
        r++;
        r=min(r,lim);
    }

    if ( b[i-1]==1 )
    {
        l--;
        l=max(l,1);
    }
}
//printf(" l = %d  r=%d  %d\n",l,r,org);
if ( ( l<=org ) && ( org<=r ) )
    return 0;
return 1;
}


void change(char ch_1,char ch_2,char s[],int a[]){
for (int i=1;i<=n;i++)
    if ( s[i]==ch_1 )
        a[i]=-1;
    else
    if ( s[i]==ch_2 )
        a[i]=1;
    else
        a[i]=0;
}

int main(){
    read(h);read(w);read(n);
    read(org_x);    read(org_y);
    scanf("%s%s",s+1,t+1);

    change('U','D',s,a);
    change('U','D',t,b);

    /*
    for (int i=1;i<=n;i++)
        printf("%d ",a[i]);
    puts("");

    for (int i=1;i<=n;i++)
        printf("%d ",b[i]);
    puts("");
    */

    if ( doit(org_x,h) )
    {
        puts("NO");
        return 0;
    }

    change('L','R',s,a);
    change('L','R',t,b);

    /*
    for (int i=1;i<=n;i++)
        printf("%d ",a[i]);
    puts("");

    for (int i=1;i<=n;i++)
        printf("%d ",b[i]);
    puts("");
    */

    if ( doit(org_y,w) )
    {
        puts("NO");
        return 0;
    }

    puts("YES");
    return 0;
}
