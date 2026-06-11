#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int > >nos(3,vector<int >(3,0));
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin>>nos[i][j];
  int diff0 = nos[0][1]-nos[0][0];
  int diff1 = nos[0][2]-nos[0][1];
  int diff2 = nos[0][2]-nos[0][0];
  int yes=1;
  for(int i=1;i<3;i++){
  	if(diff0 != nos[i][1]-nos[i][0]){yes=0;break;}
  	if(diff1 != nos[i][2]-nos[i][1]){yes=0;break;}
  	if(diff2 != nos[i][2]-nos[i][0]){yes=0;break;}

  
  }
  if(yes==1)cout<<"Yes";
  else cout<<"No";
}