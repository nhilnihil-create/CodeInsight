#include <bits/stdc++.h>
using namespace std;

int main(){
int d[3];
  for(int i=0;i<3;i++) cin >> d[i];
  sort(d,d+3);
  int a=d[0];
  int b=d[1];
  int c=d[2];
  int count=0;

count+=c-b;
a+=c-b;  
if((c-a)%2==0)count+=(c-a)/2;
else{
  count+=(c-a)/2+2;
}


  cout << count << endl;
}
