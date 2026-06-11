#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin>>n>>x;
  vector<int> a;
  int b;
  for(int i=0;i<n;i++){
    cin>>b;
    a.push_back(b);
  }
  int saishou=*min_element(a.begin(),a.end());
  for(int i=0;i<n;i++){
    x-=a[i];
  }
  while(x>0){
    x-=saishou;
    if(x<0){
      break;
    }
    n++;
  }
  cout<<n<<endl;
}