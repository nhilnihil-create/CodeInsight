#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long i = 0; i < n; i++)
#define erep(i, n) for(long i = 1; i <= n; i++)
const long MOD = 1000000007;
#define all(a) a.begin(), a.end()
#define eall(a) a.begin()+1, a.end()
#define show(ans)  cout << ans << endl;

char board[101][101];

int main(){
long A, B;
cin >> A >> B;
erep(i, 100){
  erep(j, 50){
    board[i][j] = '#';
  }
  for(long j = 51; j <= 100; j++){
    board[i][j] = '.';
  }
}


erep(i, ((A-1)/24)){
  erep(j, 24){
    board[2*i][2*j] = '.';
  }
}
erep(j, ((A-1)%24)){
  board[((A-1)/24)*2+2][j*2] = '.';
}
erep(i, ((B-1)/24)){
  for(long j = 1; j <= 24; j++){
    board[2*i][2*j+50] = '#';
  }
}
for(long j = 1; j <= ((B-1)%24); j++){
  board[((B-1)/24)*2+2][j*2+50] = '#';
}

cout << 100 << ' ' << 100 << endl;
erep(i, 100){
  erep(j, 100){
    cout << board[i][j];
  }
  cout << endl;
}







return 0;
}