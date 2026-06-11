#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,z,w;
    cin>>n>>z>>w;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<int>> x(n+1,vector<int>(n+1)),
                        y(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++){
        if(i==0)x[n][i]=abs(z-a[n-1]);
        else x[n][i]=abs(a[i-1]-a[n-1]);
    }
    for(int i=0;i<n;i++){
        if(i==0)y[i][n]=abs(w-a[n-1]);
        else y[i][n]=abs(a[i-1]-a[n-1]);
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==j)continue;
            if(j+1!=i){
                x[i][j]=y[i][j+1];
            }else{
                x[i][j]=y[i][j+2];
            }
            if(i>j){
                x[i][j]=min(x[i][j],x[i+1][j]);
            }else{
                x[i][j]=x[j+1][j];
            }
            if(i+1!=j){
                y[i][j]=x[i+1][j];
            }else{
                y[i][j]=x[i+2][j];
            }
            if(i<j){
                y[i][j]=max(y[i][j],y[i][j+1]);
            }else{
                y[i][j]=x[i][i+1];
            }
        }
    }
    cout<<y[0][1]<<endl;
}
