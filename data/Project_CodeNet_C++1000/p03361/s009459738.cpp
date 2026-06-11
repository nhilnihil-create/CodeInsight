#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;
  cin>>h>>w;
  vector<vector<char > >mat(h,vector<char >(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)cin>>mat[i][j];
  int pos=1;
  int count=0;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++){
      if(mat[i][j]=='.')continue;
      count=0;
      for(int k=-1;k<=1;k++)
        for(int l=-1;l<=1;l++)
        	if((k==0 || l==0) && !(k==0 && l==0))
            	if(i+k>=0 && i+k<h && j+l>=0 && j+l<w && mat[i+k][j+l]=='#')count++;
        if(count==0)pos=0;
    }
  if(pos==1)cout<<"Yes\n";
  else cout<<"No\n";
    
}