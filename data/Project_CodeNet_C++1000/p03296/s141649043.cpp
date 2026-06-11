#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int main(){
    int n;scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int ans=0,now=101;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            ans++;
            a[i]=now;
            now++;
        }
    }
    printf("%d\n",ans);
    return 0;
}