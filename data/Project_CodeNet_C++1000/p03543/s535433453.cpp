#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a ;
b=a%1000;
c=a-a%10;
if(b%111==0||c%111==0)
{
  cout << "Yes"<< endl;
}
else{
cout << "No"<< endl;
}
}