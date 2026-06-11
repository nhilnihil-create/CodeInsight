#include<bits/stdc++.h>
using namespace std;
 
int main(void)
{
  int N, X, m, min, s;
  s = 0;
  min = 1001;
  cin >> N >> X;
  for(int i = 0; i < N; i++){
    s++;
  	cin >> m;
    X -= m;
    if( m < min){
    	min = m;
    }
  }
  while(X >= min){
  	s++;
    X -= min;
  }
  cout << s << endl;
}