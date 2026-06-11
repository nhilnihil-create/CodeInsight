#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define int long long
#define puts(x) cout<<x<<endl
#define inf 243000000000000001
#define minf -243000000000000001
#define in(v) (v).begin(),(v).end()


signed main(){
    int n;
    cin>>n;
    int data[n][3];
    for(int i=0; i<n;i++){
        for(int j=0; j<3;j++){
            cin>>data[i][j];
        }
    }



    
    int ans [n][3];
    ans[0][0]=data[0][0];
    ans[0][1]=data[0][1];
    ans[0][2]=data[0][2];
    for(int j=0;j<3;j++){
        
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                ans[i][j]=max(ans[i-1][1],ans[i-1][2])+data[i][j];
            }
            else if(j==1){
                ans[i][j]=max(ans[i-1][0],ans[i-1][2])+data[i][j];
            }
            else if(j==2){
                ans[i][j]=max(ans[i-1][1],ans[i-1][0])+data[i][j];
            }
          
        }
        
    }

    
    puts(max(max(ans[n-1][0],ans[n-1][1]),ans[n-1][2]));
}