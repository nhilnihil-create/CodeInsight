#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int n=100001;
int a[n];
 
int main(){
  for(int i=0;i<n;i++){
    a[i]=1;
  }
  for(int i=2;i<sqrt(n);i++){
    if(a[i]){
      for(int j=0;i*(j+2)<n;j++){
        a[i*(j+2)]=0;
      }
    }
  }
  a[0]=a[1]=0;
  vector<int> b(n,0);
  for(int i=3;i<n;i+=2){
    if(a[i]==1&&a[(i+1)/2]==1) b[i]=1;
  }
  for(int i=1;i<n;i++){
    b[i]+=b[i-1];
  }
  int q;cin>>q;
  vector<int> ans(q);
  for(int i=0;i<q;i++){
    int l,r;cin>>l>>r;
    ans[i]=b[r]-b[l-1];
  }
  for(int i=0;i<q;i++) cout<<ans[i]<<endl;
}