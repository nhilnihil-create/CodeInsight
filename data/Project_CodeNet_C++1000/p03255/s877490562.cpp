#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <map>
#include <set>
#include <list>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

int i,j,k,l,m,n;
/////////////////////////////////////////////////////

ll N,X;
ll x[202020];
ll suma[202020];
ll ref;

inline ll getting(ll i,ll x){
    return i==1?5*x:(i*2+1)*x;
}

int main(){
    scanf("%lld%lld",&N,&X);
    for(i=1;i<=N;i++){
        scanf("%lld",&x[i]);
    }
    
    for(i=1;i<=N;i++){
        suma[i]=suma[i-1]+x[N-i+1];
        //printf("\n%lld ",suma[i]);
    }

    ref=LLONG_MAX;
    
    for(i=1;i<=N;i++){
        j=N/i*i;
        ll sum=getting(j/i+1,suma[N]-suma[j]);
        for(;j>=1&&sum>=0;j-=i){
            sum+=getting(j/i,suma[j]-suma[j-i]);
        }
        //printf("\n%d:%lld ",i,sum);
        if(sum<0)
            continue;
        sum+=X*i;
        if(sum<ref&&sum>0)ref=sum;
    }
    printf("%lld\n",ref+X*N);

    return 0;
}