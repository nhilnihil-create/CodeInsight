#include<bits/stdc++.h>
using namespace std;
#define     siii(a,b,c)       scanf("%d%d%d",&a,&b,&c)
#define     si(a)             scanf("%d",&a)
#define     sii(a,b)          scanf("%d%d",&a,&b)
#define     sl(a)             scanf("%lld",&a);
#define     sll(a,b)          scanf("%lld%lld",&a,&b);
#define     slll(a,b,c)       scanf("%lld%lld%lld",&a,&b,&c);
#define     sd(a)             scanf("%lf",&a);
#define     sdd(a,b)          scanf("%lf%lf",&a,&b);
#define     pb(a)             push_back(a)
#define     deb(a)            printf("### %d ###\n",a)
#define     mp                make_pair
#define     pf                printf
#define     fl(a, b, c)       for(int a= b ;a<c;a++)
#define     mx                100000 //10^5
#define     fread             freopen("input.txt","r",stdin)
#define     CLR(a,b)          memset(a,b,szof(a))
#define     ll                long long
#define     D(x)              cout<<#x" = "<<x<<endl;
#define     sz                10000
#define     bl                printf("\n")
#define     spc               printf(" ")


int main()
{
    string ans ="";
    string s;
    cin>>s;
    int w;
    si(w);
    int n = w;
    int ln = s.length();
    fl(i,0,ln){
        if(n == w){
            ans+=s[i];
        }
        n--;
        if(!n){
            n = w;
        }


    }
    cout<<ans<<endl;



    return 0;
}
