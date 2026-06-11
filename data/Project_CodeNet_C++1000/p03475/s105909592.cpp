#include <iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int c[n],s[n],f[n];
    for (int i = 0;i<n-1;i++){
        cin>>c[i]>>s[i]>>f[i];
    }
    c[n-1]=0;s[n-1]=0;f[n-1]=1;
    
    for (int x=0;x<n-1;x++){
        int ans=s[x];
        for (int i = x;i<n-1;i++){
            ans += c[i];
            if (ans%f[i+1]>0){
                ans+=(f[i+1]-ans%f[i+1]);
            }
            ans=max(ans,s[i+1]);
        }
        cout<<ans<<endl;
    }
    cout<<0;
}
