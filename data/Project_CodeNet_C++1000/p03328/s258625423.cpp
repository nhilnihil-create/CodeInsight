#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int delta=b-a;
  int large=delta*(delta+1)/2;
  cout << large-b << endl;
}