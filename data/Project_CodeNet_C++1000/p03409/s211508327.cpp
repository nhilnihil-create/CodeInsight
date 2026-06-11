#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define ll long long
#define ld long double


int main(){

int n;
cin>>n;

vector<vector<int>> red(n,vector<int>(2,0));
vector<vector<int>> blue(n,vector<int>(2,0));

rep(i,n){
    cin>>red[i][0]>>red[i][1];
}
 

rep(i,n){
    cin>>blue[i][0]>>blue[i][1];
}   

sort(red.begin(),red.end());
reverse(red.begin(),red.end());
  int ans=0;
  vector<bool>ch(n);
  rep(i,n){
    int now=1001001001;
    int co=-1;
    rep(j,n){
      if(!ch[j]&&red[i][0]<blue[j][0]&&red[i][1]<blue[j][1]){
        if(now>blue[j][1]){
          now=blue[j][1];
          co=j;
        }
      }
    }
    if(co>=0){
      ans++;
      ch[co]=true;
    }
  }
  
  cout<<ans<<endl;
}