#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m,c;
  cin>>n>>m>>c;
  vector<int> B(m);
  for(int i=0;i<m;i++)cin>> B[i];
  vector<vector<int>> A(n,vector<int> (m));
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
 cin>>A[i][j];
 
 }
 }
  int count=0;
  int sum=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(j !=m-1){sum += (A[i][j] * B[j]);}
        else{
          sum += (A[i][j] * B[j]);
          if(sum + c > 0){
        count++;
        sum=0;}
             else{sum=0;}
           
            
       }
      
    }
  }
  cout<<count<<endl;
}