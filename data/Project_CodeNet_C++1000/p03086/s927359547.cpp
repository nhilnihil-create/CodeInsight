#include <bits/stdc++.h>
using namespace std;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{

  string s="aa";
  char good[4] = {'A', 'C', 'G', 'T'};
  int ans = 0;
  cin >> s;
  s+="O";
  int size = s.length();
  REP(i,0,size){
    REP(j,0,4){
      if(s[i] == good[j]){
        int count=1;
        REP(i2,i+1,size){
          bool ok = false;
          REP(j2,0,4){
            if(s[i2] == good[j2]){
              count++;
              ok=true;
              break;
            }
          }
          if(ok==false || i2==size-1){
            if(ans<count){
              ans=count;
            }
            break;
          }
        }
      }
    }
  }

  cout << ans << endl;

  //--debug_end_stoper
  //string nanikayo; cin >> nanikayo;

  return 0;
}