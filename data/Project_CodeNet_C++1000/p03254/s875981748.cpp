#include <bits/stdc++.h>
using namespace std;

int main(){
int n,x;
  cin >> n >> x;
int a[n];
  for(int i=0;i<n;i++){
  cin >> a[i];  
  }
  sort(a,a+n);
  int count=0;
for(int i=0;i<n;i++){
  x-=a[i];
 count++;
  if(x<=0)break;
} 

 
  if(x==0) cout << count << endl;
  else    cout << count-1 << endl;
}