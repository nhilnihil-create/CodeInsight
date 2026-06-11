#include <bits/stdc++.h>
using namespace std;

int main() {
  int A , B , c;
  c=0;
  cin>>A>>B;
  for(int i=A ; i<=B ; i++){
    int d,e,f,g,h;
    d=i%10;
    e=(i-d)%100/10;
    f=(i-e*10-d)%1000/100;
    g=(i-f*100-e*10-d)%10000/1000;
    h=(i-g*1000-f*100-e*10-d)/10000;
    if(d==h && e==g){
      c++;
    }
  }
  cout<< c <<endl;
}
  