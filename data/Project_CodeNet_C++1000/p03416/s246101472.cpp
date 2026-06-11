#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  
  int cnt=0;
  for(int i=A;i<=B;i++){
    int a=i%10;
    int b=(i/10)%10;
    int d=(i/1000)%10;
    int e=i	/10000;
    if(a==e && b==d){
    cnt++;
    }
  }
  cout << cnt <<endl;
}
