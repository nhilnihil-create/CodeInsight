#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  int a,b,c,d,e,k;
  cin >> a >> b >> c >> d >> e >> k;
  int flag=0;
  if(b-a>k){
    flag++;
  }
  if(c-a>k){
    flag++;
  }
  if(d-a>k){
    flag++;
  }
  if(e-a>k){
    flag++;
  }
  if(c-b>k){
    flag++;
  }
  if(d-b>k){
    flag++;
  }
  if(e-b>k){
    flag++;
  }
  if(d-c>k){
    flag++;
  }
  if(e-d>k){
    flag++;
  }
  if(e-c>k){
    flag++;
  }

  if(flag==0){
    cout << "Yay!" << endl;
  }
  else{
    cout << ":(" << endl;
  }
}