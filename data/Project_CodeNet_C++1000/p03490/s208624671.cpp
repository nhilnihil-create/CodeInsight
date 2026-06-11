#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#define REP(i,n) for(int i=0;i<(n);++i)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
 
int main(){
  string S;
  int dest[2];
  cin >> S >> dest[0] >> dest[1];
  int len = S.size();
  int mode = 0, cdist = 0, firstmove = 1;
  int visited[2][16001] = {};
  visited[0][8000] = 1; visited[1][8000] = 1;
  REP(i,len) {
    if(S[i] == 'T') {
      if(cdist != 0) {
        int nvisited[16001] = {};
        if(firstmove) {
          nvisited[8000 + cdist] = 1;
        } else {
          REP(j, 16001) {
            if(visited[mode][j]) {
              nvisited[j + cdist] = 1;
              nvisited[j - cdist] = 1;
            }
          }
        }
        REP(j, 16001) {
          visited[mode][j] = nvisited[j];
        }
      }
      mode = !mode;
      cdist = 0;
      firstmove = 0;
    } else {
      cdist++;
    }
  }
  if(cdist != 0) {
    int nvisited[16001] = {};
    if(firstmove) {
      nvisited[8000 + cdist] = 1;
    } else {
      REP(j, 16001) {
        if(visited[mode][j]) {
          nvisited[j + cdist] = 1;
          nvisited[j - cdist] = 1;
        }
      }
    }
    REP(j, 16001) {
      visited[mode][j] = nvisited[j];
    }
  }
  
  int ret = 1;
  REP(m, 2) {
    ret &= visited[m][8000 + dest[m]];
  }
  cout << (ret ? "Yes" : "No") << endl;
}