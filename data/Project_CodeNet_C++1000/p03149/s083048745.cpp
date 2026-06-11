#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int>A(4);
  for(int i=0;i<4;i++)cin>>A[i];
  sort(A.begin(),A.end());
  cout<<(A[0]==1&&A[1]==4&&A[2]==7&&A[3]==9? "YES":"NO")<<endl;
}