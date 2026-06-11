#include <iostream>
using namespace std;
int n,x[200000],a[200000];
long long ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i&&a[i-1]+1<a[i]||!i&&a[i]){
            cout<<-1;
            return 0;
        }
    }
    for(int i=n-1;i;i--)if(a[i-1]>=a[i])ans+=a[i-1];
    cout<<a[n-1]+ans<<endl;
}