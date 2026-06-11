#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b>> c;
  int answer;
  if(a==b){
    answer=c;
  }else if(b==c){
    answer = a;
  }else{
    answer=b;
  }
  cout << answer << endl;
  return 0;
}