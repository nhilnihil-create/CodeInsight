#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,sum=1;
  cin>>n;
  vector<int> mochid(n);
  for(int i=0;i<n;i++){
    cin>>mochid.at(i);
  }
 sort(mochid.begin(),mochid.end());
 
  for(int i=1;i<n;i++){
		if(mochid.at(i)!=mochid.at(i-1)){
          sum++;
        }else{

  
        }
        }
  cout<<sum<<endl;
}