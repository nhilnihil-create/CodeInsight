#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int count=0;
  for(int i=0;i<a-1;i++){
    count++;
  }
  if(a<=b){
    count++;
  }
  cout << count << endl;
}