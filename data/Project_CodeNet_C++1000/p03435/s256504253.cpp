#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  vector<vector<int>> c(3,vector<int>(3));
  rep(i,3)rep(j,3)
    cin>>c[i][j];
  
  rep(i,2){
    rep(j,2){
       if(c[i][j + 1] - c[i][j] != c[i + 1][j + 1] - c[i + 1][j]){
          cout<<"No"<<endl;
          return 0;
       }
    }
    rep(j,2){
       if(c[j + 1][i] - c[j][i] != c[j + 1][i + 1] - c[j][i + 1]){
          cout<<"No"<<endl;
          return 0;
       }
    }
  }
  cout<<"Yes"<<endl;
}