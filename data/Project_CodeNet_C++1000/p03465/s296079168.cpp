#include<bits/stdc++.h>

using namespace std;

const int maxn=4e6+10;

bitset<maxn> b;

int main(){

    int n;
    scanf("%d",&n);
    b[0]=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        b|=b<<x;
        sum+=x;
    }
    for(int i=(sum+1)/2;i<=sum;i++){
        if(b[i]) {
            printf("%d\n",i);
            return 0;
        }
    }
}
