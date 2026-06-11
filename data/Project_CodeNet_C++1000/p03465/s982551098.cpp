#include<bits/stdc++.h>
using namespace std;
bitset<5000000>s;
int main(){
    int n,x,sum=0;
    scanf("%d",&n);
    s[0]=1;
    for(int i=0;i<n;i++)
        scanf("%d",&x),s|=s<<x,sum+=x;
    for(int i=(sum+1)>>1;;i++)
    if(s[i]){
            printf("%d",i);
            return 0;
    }
    return 0;
}
