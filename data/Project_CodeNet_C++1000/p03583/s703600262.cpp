#include<bits/stdc++.h>
using namespace std;
bool chkInt(double a){
  return a == (int)a;
}

int main(){
  long n;
  cin >> n;
  int a,b,c;
  int i,j;
  for(i=1;i<=3500;i++){
    for(j=1;j<=3500;j++){
      long tmp = 4*i*j-n*(i+j);
      if(tmp>0 && chkInt((double)(n*i*j)/tmp)){
        a = i;
        b = j;
        c = (n*i*j)/tmp;
      }
    }
  }




  cout << a << " " << b <<" "<<c<<endl;


}
