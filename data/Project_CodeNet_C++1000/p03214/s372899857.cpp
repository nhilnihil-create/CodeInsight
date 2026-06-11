#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int cut=1000000;
    for(int i=0;i<n;i++){
        cut=min(cut,abs(sum-a[i]*n));
    }
    int ans;
    for(int i=0;i<n;i++){
        if(abs(sum-a[i]*n)==cut){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
