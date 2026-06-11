#include<bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin>>s;
  set<int> c;
  int n=1;
  while(1){
    if(c.count(s)){
      cout<<n<<endl;
      break;
    }else{
      c.insert(s);
      if(s%2==0)
        s/=2;
      else
        s=s*3+1;
      n++;
    }
  }
}