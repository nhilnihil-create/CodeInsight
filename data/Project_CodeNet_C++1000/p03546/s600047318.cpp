#include<bits/stdc++.h>
using namespace std;
int c[10][10];
int C[10];
int a[10];
void solve(int n){
    a[0]=1;
    if(n==10){
        int tmp=0;
        for(int i=1;i<10;i++){
            tmp += c[a[i]][a[i-1]];
            C[a[i]]=min(C[a[i]],tmp);
        }
    }
    else{
        int cou[10];
        for(int i=0;i<10;i++)cou[i]=0;
        for(int i=0;i<n;i++)cou[a[i]]=1;
        for(int i=0;i<10;i++){
            if(cou[i]==0){
                a[n]=i;
                solve(n+1);
            }
        }
    }
}
int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)cin >> c[i][j];
        C[i]=c[i][1];
    }
    solve(1);
    int x;
    int ans=0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        cin >> x;
        if(x>1 || x==0)ans+=C[x];
    }
    cout << ans;
}