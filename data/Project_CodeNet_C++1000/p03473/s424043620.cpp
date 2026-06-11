#include <bits/stdc++.h>
using namespace std;

int main(){
  int day = 24;
  int now_hour;
  
  cin >> now_hour;
  
  int last = 24 - now_hour;
  
  cout << day + last << endl;
}