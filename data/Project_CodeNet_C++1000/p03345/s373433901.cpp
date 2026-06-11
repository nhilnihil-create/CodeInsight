#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c,num;
  long long tmpMax;
  long long tmpA,tmpB;
  long long kekka;
  
  cin >> a >> b >> c >> num;
  
  if(a == b && b == c){
    cout << 0;
  }else if(num == 1){
    tmpA = b + c;
    tmpB = a + c;
    kekka = tmpA - tmpB;
    
    if(kekka > 1000000000000000000) cout << "Unfair";
    else cout << kekka;
  }else{
    if(num % 2 == 0){
      //偶数回は自分だけ回数+1倍
      tmpA = ((num+1) * a) + (num * b) + (num * c);
      tmpB = (num * a) + ((num+1) * b) + (num * c);
      kekka = tmpA - tmpB;
      
      if(kekka > 1000000000000000000) cout << "Unfair";
      else cout << kekka;
    }else{
      //奇数回は自分だけ回数-1倍
      tmpA = ((num-1) * a) + (num * b) + (num * c);
      tmpB = (num * a) + ((num-1) * b) + (num * c);
      kekka = tmpA - tmpB;
      
      if(kekka > 1000000000000000000) cout << "Unfair";
      else cout << kekka;
    }
  }
}