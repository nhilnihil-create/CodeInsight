 #include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y; cin >> N >> Y;
  bool lie = true;
  for(int i = 0; i <=N;i++){
     if(!lie) break;
    for(int j = 0; j <=N;j++){
      int total = 10000*i+5000*j+1000*(N-i-j);
      if(total==Y && i+j <= N ){
        cout << i << " " << j << " " << N-j-i << endl;
        lie = false;
        break;
      }
     
    }
   
  }
 if(lie) cout << -1 << " " << -1 << " " << -1 << endl;
}

