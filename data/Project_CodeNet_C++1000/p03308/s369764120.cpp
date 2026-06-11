#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
  cin >> N;
  int a[110];
  int x,y;
  
  for(int i=0;i<N;i++) cin >> a[i];
    x=a[0];
    y=a[0];
  for(int i=0;i<N-1;i++){
    if(x>a[i+1])x=a[i+1];
    if(y<a[i+1])y=a[i+1];
  }
  cout << y-x << endl;

}