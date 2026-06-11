#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[2][n];
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)cin>>a[i][j];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp=0;
        for(int j=0;j<=i;j++){
            tmp+=a[0][j];
        }
        for(int j=i;j<n;j++){
            tmp+=a[1][j];
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}