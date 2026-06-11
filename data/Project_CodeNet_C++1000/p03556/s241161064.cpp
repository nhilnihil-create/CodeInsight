#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,ans=0;
  cin >> N;
  int i = 1;
  do{
    ans = i * i;
    i++;
  }while( i * i <= N);
  
  printf("%d",ans);
}