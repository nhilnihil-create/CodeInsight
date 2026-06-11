#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

int n;
long long a[100];

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int mi = 0;
  int ma = 0;
  for(int i=0;i<n;i++){
    if(abs(a[i]) > ma){
      mi = i;
      ma = abs(a[i]);
    }
  }
  cout<<(2*n-2)<<endl;
  for(int i=0;i<n;i++)if(mi != i){
    cout<<(mi+1)<<" "<<(i+1)<<endl;
  }
  if(a[mi] > 0){
    for(int i=0;i<n-1;i++){
      cout<<(i+1)<<" "<<(i+2)<<endl;
    }
  } else {
    for(int i=n-1;i>0;i--){
      cout<<(i+1)<<" "<<(i)<<endl;
    }
  }

  return 0;
}