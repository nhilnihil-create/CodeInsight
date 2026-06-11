#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int count=0;
  while(1){
    bool TF=true;
  	for(int i=0;i<n;i++){
    	if(a[i]%2==0 && TF){
      		a[i]/=2;
      		TF=false;
    	}else{
      		a[i]*=3;
    	}
  	}
    if(TF==true){
      cout<<count<<endl;
      return 0;
    }
    count++;
  }
}