#include<bits/stdc++.h>
using namespace std;
int sum(int i){
  int sum=0;
   while(i>0){
      sum+=i%10;
      i/=10;
    }
  return sum;
}
int main(){
  int n;
  int min=1<<30;
  cin >>n;
  for(int i=1;i<n;i++){
    int j=n-i;
    int k=sum(i)+sum(j);
    if(min>k)min=k;
  }
  cout << min << endl;
}

      
