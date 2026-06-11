#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0,flag=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(1){
        for(int j=0;j<n;j++){
            if(a[j]%2==1){
                flag=1;
            } else {
                a[j]/=2;
            }
        }
        if(flag==0){
            ans++;
        } else if(flag==1){
            break;
        }
    }
        cout<<ans;
}
            