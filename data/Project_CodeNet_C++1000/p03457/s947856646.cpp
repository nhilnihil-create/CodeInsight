#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  int t[110000];
  int x[110000];
  int y[110000];
  t[0]=0;
  x[0]=0;
  y[0]=0;

  cin >> N;
  for (int i = 1; i < N+1; i++)
  {
    cin >> t[i] >> x[i] >> y[i];
  }

  bool flag=true;
  for (int i = 1; i < N+1; i++)
  {
    int dist=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    int tdist = t[i] - t[i-1];
    if(tdist>=dist){
      if(tdist%2 == 0){
        if(dist%2 != 0){
          flag=false;
          break;
        }
      }else{
        if(dist%2 != 1){
          flag=false;
          break;
        }
      }
    }else{
      flag=false;
      break;
    }
    // cout << dist << endl;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}