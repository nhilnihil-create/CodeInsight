#include <bits/stdc++.h>
using namespace std;

int func(int n){
  if (n%2==0){
    return n/2;
  }else{
    return 3*n+1;
  }
}

int a(int i,int s){
  if (i==1){
    return s;
  }else{
    return func(a(i-1,s));
  }
} 

int main(){
  int s;
  cin>>s;
  multiset<int> x;
  for (int i=1; i<=1000000; i++){
    if (find(x.begin(),x.end(),a(i,s))!=x.end()){
      cout<<i<<endl;
      break;
    }
    x.insert(a(i,s));
  }
}
  