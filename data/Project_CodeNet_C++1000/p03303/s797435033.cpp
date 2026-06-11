#include<bits/stdc++.h>
using namespace std;

#define     fRead           freopen("INPUT.txt","r",stdin)
#define     fWrite          freopen("OUTPUT.txt","w",stdout)
#define     ss(a)           scanf("%s",a)
#define     gs(s)           getline(cin,s)
#define     gc              getchar()
#define     si(a)           scanf("%d",&a)
#define     sii(a,b)        scanf("%d%d",&a,&b)
#define     siii(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define     sl(a)           scanf("%lld",&a)
#define     sll(a,b)        scanf("%lld%lld",&a,&b)
#define     slll(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define     sd(a)           scanf("%lf",&a)
#define     sdd(a,b)        scanf("%lf%lf",&a,&b)
#define     sddd(a,b,c)     scanf("%lf%lf%lf",&a,&b,&c)
#define     deb(x)          cout << #x " = " <<(x) << endl
#define     debb            printf("####\n")
#define     pi(a)           printf("%d",a)
#define     ps(a)           cout<<a
#define     pl(a)           printf("%lld",a)
#define     pd(a)           printf("%f",a)
#define     pc(a)           printf("%c",a)
#define     bl              printf("\n")
#define     spc             printf(" ")
#define     ll              long long
#define     llu             unsigned long long
#define     pie             2*acos(0.0)
#define     eps             1e-9
#define     qi              queue<int>
#define     vi              vector<int>
#define     vs              vector<string>
#define     vd              vector<double>
#define     vl              vector<long long>
#define     pb(a)           push_back(a)
#define     pii             pair <int,int>
#define     CLR(a)          memset(a,0,sizeof(a))
#define     fl(i,a,n)       for(int i=a; i<n; i++)
#define     rfl(i,n,a)      for(int i=n-1; i>=a; i--)
#define     fit(x,mp)       for(auto x = mp.begin(); x!=mp.end(); x++)
#define     MAX             1000000 //10^6
int a,b,n,tmp,flag;
char s[MAX+5];
int main()
{
    ss(s);
    si(n);

    fl(i,0,strlen(s))
    {
        if(i%n==0) pc(s[i]);
    }

    return 0;
}





