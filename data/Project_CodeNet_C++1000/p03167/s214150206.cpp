#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main() {
    int n,m;
    cin>>n>>m;
    vector <vector <int>> answer(n,vector<int>(m));
    vector <vector <int>> ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char input;
            cin>>input;
            if(input=='.')answer[i][j]=0;
            else answer[i][j]=-1;
        }
    }
    ans[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(answer[i][j]==-1){
                ans[i][j]=0;
                continue;
            }
            if(i==0 && j==0)continue;
            if(i==0){
                if(answer[i][j-1]==-1)ans[i][j]=0;
                else ans[i][j]=ans[i][j-1];
                continue;
            }
            if(j==0){
                if(answer[i-1][j]==-1)ans[i-1][j]=0;
                else ans[i][j]=ans[i-1][j];
                continue;
            }
            ans[i][j]=(ans[i][j-1]%mod+ans[i-1][j]%mod)%mod;
        }
    }cout<<ans[n-1][m-1]<<endl;
    
    
}
