#include <bits/stdc++.h>
#define maxn 4000005
using namespace std;
bitset<maxn>bit;
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    bit[0]=1;
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        sum+=num;
        bit|=bit<<num;
    }
    int j=(sum+1)>>1;
    for(int i=j;i<=sum;i++){
        if(bit[i]){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
