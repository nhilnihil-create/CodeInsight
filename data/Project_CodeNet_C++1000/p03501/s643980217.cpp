#include<iostream>

using namespace std;

int main(){
  int N,a,b;
  cin >> N >> a >> b;
  int X = N*a;
  if(X<b){
    cout << X << endl;
  }else{
    cout << b << endl;
  }
}