#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],ans,n;
vector<int>ve;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    long long tmp=0;
    for(int i=0;i<=29;i++){
        ve.clear();
        int mod=(1<<(i+1));
        for(int j=1;j<=n;j++)ve.push_back(b[j]%mod);
        mod/=2;
        sort(ve.begin(),ve.end());
        tmp=0;
        for(int j=1;j<=n;j++){
            int tmpl,tmpr;
            tmpl=lower_bound(ve.begin(),ve.end(),mod*1-a[j]%(mod*2))-ve.begin()-1;
            tmpr=lower_bound(ve.begin(),ve.end(),mod*2-a[j]%(mod*2))-ve.begin()-1;
            tmp+=tmpr-tmpl;
            tmpl=lower_bound(ve.begin(),ve.end(),mod*3-a[j]%(mod*2))-ve.begin()-1;
            tmpr=lower_bound(ve.begin(),ve.end(),mod*4-a[j]%(mod*2))-ve.begin()-1;
            tmp+=tmpr-tmpl;
        }
        if(tmp%2==1)ans=(1<<i)|ans;
    }
    printf("%d\n",ans);

}