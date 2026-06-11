#include <iostream>
#include <algorithm>
using namespace std;
int n,p,_p[200001],cnt,ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>p,_p[p]=i;
    for(int i=1;i<n;i++){
        if(_p[i]<_p[i+1])cnt++;
        else cnt=0;
        ans=max(ans,cnt);
    }
    cout<<n-ans-1<<endl;
    return 0;
}