#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  char a,b;
  cin>>a>>b;
  if(a==b){
    cout<<"="<<endl;
  }else if(a>b){
    cout<<">"<<endl;
  }else{
    cout<<"<"<<endl;
  }
}
