#include<bits/stdc++.h>

#define             ll                      long long
#define             si(a)                   scanf("%d",&a)
#define             sii(a,b)                scanf("%d%d",&a,&b)
#define             siii(a,b,c)             scanf("%d%d%d",&a,&b,&c)
#define             s(a)                    scanf("%s",a)
#define             ss(a,b)                 scanf("%s%s",a,b)
#define             pii                     pair<int,int>
#define             pb(a)                   push_back(a)
#define             fr(i,n)                 for(int i=0;i<n;i++)
#define             pri(a)                  printf("%d ",a)
#define             bl                      printf("\n")
#define             PI                      2*acos(0.0)
#define             inf                     1000000
#define             sz                      100
#define             MOD                     1000000007
#define             base                    2147483647
#define             vsort(a)                sort(a.begin(),a.end())
#define             EPS                     10E-10
#define             gcd(a, b)               __gcd(a, b)
#define             lcm(a, b)               ((a)*((b)/gcd(a,b))
#define             finput                  freopen("input.txt","r",stdin)
#define             foutput                 freopen("output.txt","w",stdout)
#define             debug(a,b)              printf("%s %d ",a,b)


//const int fx[]={1,-1,0,0};
//const int fy[]={0,0,1,-1};
//const int fx[]={0,0,1,-1,-1,1,-1,1};   // Kings Move
//const int fy[]={-1,1,0,0,1,1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move


using namespace std;


int main()
{

    string s;
    int n;

    cin>>s>>n;

    int l = s.length();

    for(int i=0;i<l;i+=n){
        printf("%c",s[i]);
    }
    printf("\n");

}
