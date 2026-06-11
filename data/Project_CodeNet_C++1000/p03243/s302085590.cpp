#include<iostream>
using namespace std;
int main(){
  int n,num=0;
  cin >> n;
  if(n/100==n%10 && (n/10)%10==n%10){
    cout << n << endl;
  }
  else{
    if(n/100<(n/10)%10){
      num=n/100;
      num++;
      cout << num*100+num*10+num << endl;
    }
    else if(n/100==(n/10)%10 && n/100<n%10){
      num=n/100;
      num++;
      cout << num*100+num*10+num << endl;
    }
    else{
      num=n/100;
      cout << num*100+num*10+num << endl;
    }
  }
}
