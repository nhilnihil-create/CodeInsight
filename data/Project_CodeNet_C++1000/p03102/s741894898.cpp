#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,c;
    cin>>n>>m>>c;
    int b[m];// = new int[m];
    for (int i = 0;i<m;i++){
        cin>>b[i];
    }
    int a[n][m];// = new int[n][m]; 
    for (int i = 0;i<n;i++){
        for (int j = 0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans =0;
    
    for (int i = 0;i<n;i++){
        int tmp=c;
        for (int j = 0;j<m;j++){
            tmp += a[i][j]*b[j];
        }
        if (tmp>0){
            ans++;
        }
    }
    cout<<ans;

    
}
