#include<bits/stdc++.h>
using namespace std;
#define ll               long long
#define dl               double
#define ull              unsigned long long
#define ft               first
#define sd               second
#define pi               acos(-1)
#define ct(tc)           scanf("%lld",&tc)
#define scnm(n,m)        scanf("%lld %lld",&n,&m);
#define max3(a,b,c)      max(a,max(b,c))
#define max4(a,b,c,d)    max(a,max(b,max(c,d)))
#define min3(a,b,c)      min(a,min(b,c))
#define min4(a,b,c,d)    min(a,min(b,min(c,d)))
#define pb               push_back
#define srt              sort(v.begin(),v.end())
#define rsrt             reverse(v.begin(),v.end())
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,m;
    scnm(n,m);
    if(n>8||m>8)
    {
        printf(":(\n");
    }
    else
    {
        printf("Yay!\n");
    }
    return 0;

}
