#include<bits/stdc++.h>
using namespace std;
int ans[2][105];
int main(){
    int n;
    cin >> n;
    int a[2][n];
    for(int i=0;i<2;i++)for(int j=0;j<n;j++)cin >> a[i][j];
    ans[0][0]=a[0][0];
    ans[1][0]=a[1][0]+a[0][0];
    if(n==1)cout << ans[1][0];
    else{
        for(int i=0;i<2;i++){
            for(int j=0;j<n-1;j++){
                if(i==0)ans[i][j+1]=ans[i][j]+a[i][j+1];
                else ans[i][j+1]=max(ans[i-1][j+1],ans[i][j])+a[i][j+1];
            }
        }
        cout << ans[1][n-1];
    }
}
