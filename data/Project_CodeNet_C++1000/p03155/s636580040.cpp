#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  int H;
  int W;
  
  cin >> N;
  cin >> H;
  cin >> W;
  
  int num = N - H + 1;
  int num2 = N - W + 1;
  
  cout << num * num2 << endl;
}
