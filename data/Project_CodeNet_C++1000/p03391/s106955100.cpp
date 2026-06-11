#include <bits/stdc++.h>
using namespace std;

long n,x,y,ans,check,num=1e10;

int main(){
  cin >> n;
  while(n--){
	cin >> x >> y;
    if(x != y)check = 1;
    if(x > y && num > y) num = y;
    ans += x;
  }
  cout << (check ? ans - num : 0) << endl;
}