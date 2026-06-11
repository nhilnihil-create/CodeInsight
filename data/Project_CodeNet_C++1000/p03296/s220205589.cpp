#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)continue;
        else{
            if(a[i]==a[i-1]){
                a[i]=n+10;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}