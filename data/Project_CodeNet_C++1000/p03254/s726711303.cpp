#include <bits/stdc++.h>
using namespace std;
int n[10000];
int main(){
  int a,b;
  cin >> a >> b;
  for(int i = 0;i < a;i++){
    cin >> n[i];
  }
  sort(n,n+a);
  int cook = 0;
  int count = 0;
  for(int i = 0;i < a;i++){
    b -= n[i];
     if(b < 0) break;
     count++;
    }
  if(b > 0) count--;
      cout << count << endl;
}
