#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;cin>>h>>w;
  	vector<vector <char> >maze(h,vector<char >(w,'.'));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>maze[i][j];
  for(int i=0;i<h;i++){
  	for(int j=0;j<w;j++){
    	if(maze[i][j]=='#')cout<<'#';
      else{
          int bombs=0;
      	for(int k=-1;k<=1;k++)
          for(int l=-1;l<=1;l++)
         	if(i+k>=0 && i+k<h && j+l>=0 && j+l<w && maze[i+k][j+l]=='#')bombs+=1;
      	cout<<bombs;
      }
    }
    cout<<'\n';
  }
}