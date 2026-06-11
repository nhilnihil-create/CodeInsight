#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int N= 200100 , shift = 100100;
int n , k , x[N] , ans = 1<<30;

ll ret;
int bit[N];
void add(int i,int x){ for(;i<N;i+=i&-i)bit[i]+=x; }
ll get(int i){ for(ret=0;i;i-=i&-i)ret+=bit[i]; return ret; }


bool ok(int M){
ll all = 1ll* n * (n+1) / 2ll;
ll cnt = 0 , sum =0 ;
memset(bit,0,sizeof bit);
add(shift,1);
for(int i=1;i<=n;i++){
    sum += ( x[i] <= M );
    cnt += get( sum+sum-i+shift-1 );
    add(sum+sum-i+shift,1);
}
return cnt+cnt > all;
}

int main(){

scanf("%d",&n);
for(int i=1;i<=n;i++)scanf("%d",x+i);

int low=1,high=1e9 +5;
while( low < high ){
    int mid = low+high>>1;
    if( ok(mid) )high=mid;
    else low=mid+1;
}
printf("%d\n",high);
return 0;
}
