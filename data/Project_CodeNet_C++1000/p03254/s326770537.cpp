#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    int ans=0;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int tmp=x;
    for(int i=0;i<n;i++){
        x-=a[i];
        if(x<0){
            break;
        }
        ans++;
    }
    if(x>0)--ans;
    cout<<ans<<endl;
    return 0;
}
