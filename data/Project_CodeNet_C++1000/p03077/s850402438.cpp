#include <iostream>
using namespace std;

int main(){
  long long  n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  long long pos = 0;
  long long time = 0;
  time = (n + (a-1)) / a;
  pos++;
  if(a <= b){
    time++;
    b = a;
  }
  else time = (n + (b-1)) / b + pos;
  pos++;
  if(b <= c){
    time++;
    c = b;
  }
  else time = (n + (c-1)) / c + pos;
  pos++;
  if(c <= d){
    time++;
    d = c;
  }
  else time = (n + (d-1)) / d + pos;
  pos++;
  if(d <= e){
    time++;
    e = d;
  }
  else time = (n + (e-1)) / e + pos;
  pos++;
  cout << time << endl;
  return 0;
}
    
  