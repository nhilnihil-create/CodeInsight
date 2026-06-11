#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int f[n][5][2];
    int p[n][11];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<2;k++)cin >> f[i][j][k];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++)cin >> p[i][j];
    }
    int ans=-1e9;
    for(int i=1;i<(1 << 10);i++){
        int tmp=0;
        for(int j=0;j<n;j++){
            int count=0;
            for(int k=0;k<10;k++){
                if( ((i & (1 << k))>0) && f[j][k/2][k%2])count++;
            }
            tmp+=p[j][count];
        }
        ans=max(ans,tmp);
    }
    cout << ans;
}