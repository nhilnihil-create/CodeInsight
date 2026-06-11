#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    int d[c][c];
    for(int i=0;i<c;i++)for(int j=0;j<c;j++)cin>>d[i][j];
    int color[n][n];
    int x[3][c];
    for(int i=0;i<3;i++)for(int j=0;j<c;j++)x[i][j]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>color[i][j];
            x[(i+j)%3][color[i][j]-1]++;
        }
    }
    int m=1000000000;
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(i==j)continue;
            for(int k=0;k<c;k++){
                if(i==k || j==k)continue;
                int iwakan=0;
                for(int l=0;l<c;l++){
                    iwakan+=x[0][l]*d[l][i];
                    iwakan+=x[1][l]*d[l][j];
                    iwakan+=x[2][l]*d[l][k];
                }
                m=min(m,iwakan);
            }
        }
    }
    cout<<m<<endl;
    return 0;
}