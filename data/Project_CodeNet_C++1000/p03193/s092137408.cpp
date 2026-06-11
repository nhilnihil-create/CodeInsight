#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >>a>>b>>c;
  int d,e,answer;
  answer=0;
  
  for(int i=0;i<a;i++){
    cin>>d>>e;
    if(d>=b&&e>=c){
      answer++;
    }
  }
  cout<<answer<<endl;
}