#include <bits/stdc++.h>
#define Rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef int64_t intl;


int main(){
  int a,b;
  cin >> a >>b;
  int no_b = b - a;
  int height_b = 0;
  Rep (i,no_b){
    height_b += i+1;
  }
  cout << height_b - b;
}
    
    