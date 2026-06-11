#include "bits/stdc++.h"
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  // 全部単体でまかなう
  int sum;
  sum = A * X + B * Y;
  int min = sum;

  // AかBの少ない方の数をCでまかなう（不足分は単体でまかなう）
  int a = X;
  int b = Y;
  sum = 0;
  while(a > 0 && b > 0){
    sum += C * 2;
    a--;
    b--;
  }
  if(a > 0){
    sum += a * A;
  }
  if(b > 0){
    sum += b * B;
  }
  if(min > sum){
    min = sum;
  }

  // AかBの多い数をCでまかなう（過分はそのままｍ）
  sum = 0;
  if(X > Y){
    sum = C * X * 2;
  }else{
    sum = C * Y * 2;
  }
  if(min > sum){
    min = sum;
  }

  cout << min << endl;
}