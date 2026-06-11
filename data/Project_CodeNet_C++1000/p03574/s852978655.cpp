#include <bits/stdc++.h>
using namespace std;

string s[100];
int n, m, arr[100][100];

int main(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> s[i];
    s[i] = "0" + s[i];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(s[i][j] == '#'){
        for(int k = -1; k <= 1; k++){
          for(int l = -1; l <= 1; l++){
            arr[i+k][j+l]++;
          }
        }
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(s[i][j] == '#'){
        cout << "#";
      }else{
        cout << arr[i][j];
      }
    }
    cout << endl;
  }
}