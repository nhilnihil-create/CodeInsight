#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long x[1010], y[1010];
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> x[i] >> y[i];
  }

  int tmp = (abs(x[0]) + abs(y[0])) % 2;
  for(int i = 1;i < n;i++){
    if((abs(x[i]) + abs(y[i])) % 2 != tmp){
      cout << -1 << endl;
      return 0;
    }
  }

  long long d[40];

  int p = 0;
  if(tmp == 0){
    d[0] = 1;
    p++;
  }
  d[p] = 1;

  int m = 33;

  for(int i = p+1;i < m;i++){
    d[i] = d[i-1]*2;
  }

  cout << m << endl;
  for(int i = 0;i < m;i++){
    cout << d[i];
    if(i != m-1) cout << " ";
  }
  cout << endl;


  for(int i = 0;i < n;i++){
    stack<char> st;

    long long nx, ny;
    nx = x[i];
    ny = y[i];
    if(tmp == 0) nx++;

    for(int i = 32;i >= (1-tmp);i--){
      long long t = nx + d[i];
      if(abs(t) + abs(ny) > d[i]){
        t = nx - d[i];
        if(abs(t)+abs(ny) > d[i]){
          t = ny+d[i];
          if(abs(t) + abs(nx) > d[i]){
            t = ny-d[i];
            ny = t;
            st.push('U');
          }else{
            ny = t;
            st.push('D');
          }
        }else{
          nx = t;
          st.push('R');
        }
      }else{
        nx = t;
        st.push('L');
      }
    }


    if(tmp == 0){
      st.push('L');
    }

    while(!st.empty()){
      cout << st.top();
      st.pop();
    }

    cout << endl;
  }
  return 0;
}


