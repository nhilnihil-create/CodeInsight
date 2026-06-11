#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M,X,Y;
  cin>>N>>M>>X>>Y;
  
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  
  vector<int> b(M);
  for(int j=0;j<M;j++){
    cin>>b[j];
  }
  sort(b.begin(),b.end());
  
  
  if(Y-X<=0){
    cout<<"War"<<endl;
  }
  else{
    vector<int> bound(Y-X);
    for(int i=0;i<Y-X;i++){
      bound[i]=i+1+X;
    }
    
    for(int i=0;i<Y-X;i++){
      if(bound[i]>a[N-1]&&bound[i]<=b[0]){
        cout<<"No War"<<endl;
        return 0;
      }
    }
    cout<<"War"<<endl;
  }
}