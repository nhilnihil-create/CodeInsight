#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>

 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define LLIandI pair<long long int , int>
#define ll long long
int main(void){
    int N;
    scanf("%d",&N);
    long long int a[200002],b[200002];//<10^9
    rep(i,N){
        scanf("%lld",&a[i]);
    }
    rep(i,N){
        scanf("%lld",&b[i]);
    }
    long long int amod[200002],bmod[200002];
    long long int ans=0;
    long long int biti=1;
    long long int biti_over=2;
    rep(i,30){
        rep(j,N)amod[j]=a[j]% biti_over;
        rep(j,N)bmod[j]=b[j]% biti_over;
        sort(&amod[0],&amod[N]);
        long long int xorabpair=0;
        rep(j,N){
            long long int xor1a_min=biti-bmod[j];
            long long int xor1a_max=biti_over-bmod[j]-1;
            long long int xor11a_min=biti+biti_over-bmod[j];
            long long int xor11a_max=biti_over+biti_over-bmod[j]-1;
            xorabpair+=abs(upper_bound(&amod[0],&amod[N],xor1a_max)-lower_bound(&amod[0],&amod[N],xor1a_min) );
            xorabpair+=abs(upper_bound(&amod[0],&amod[N],xor11a_max)-lower_bound(&amod[0],&amod[N],xor11a_min) );
        }
        ans+=(xorabpair%2)*biti;
        biti*=2;biti_over*=2;
    }
    printf("%lld\n",ans);
    
}
