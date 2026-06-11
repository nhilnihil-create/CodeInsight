#include <iostream>
#include <string.h>
using namespace std;

int main () {
  int a, b;
  cin >> a >> b;
  int m = a;
  int n = b;
  if (m < n) {
    swap(m, n);  
  }  
 int dp[100][100];
 int num = 0;
 int nun = 0;
 bool forbool = false;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = 0;  
    }  
  }
  if (m == 1 || n == 1) {
    if (m == 1 && n == 1) {
      cout << "1 2" << endl;
      cout << ".#" << endl;  
      return 0;
    }    
    if (n == 1) {
      for (int j = 0; j < 100; j++) {
        dp[0][j] = -1;  
      }
      for (int i = 1; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
          if (i % 2 == 0) {
            dp[i][j] = -1;      
          }  
          else {
            if (j % 2 == 0) {
              dp[i][j] = 1; 
              num++; 
            }  
            else {
              dp[i][j] = -1;  
            }
          }
          if (num == m) {
            forbool = true;
            break;  
          }
        }  
        if (forbool) break;
      }
      for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
          if (dp[i][j] == 0) {
            dp[i][j] = -1;  
          }  
        }  
      }
    }
  }
  else {
    for (int j = 0; j < 100; j++) {
      dp[0][j] = -1;
    } 
    int memory = 0;
    for (int i = 1; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        if (i % 2 == 0) {
          dp[i][j] = -1;  
        }  
        else {
          if (i == 1) {
            if (j % 2 == 0) {
              dp[i][j] = 1; 
              num++; 
            }  
            else {
              dp[i][j] = -1;  
            }
          }
          else {
            dp[i][j] = dp[i - 2][j] * -1;  
            if (dp[i][j] == 1) {
              num++;  
            }
          }
        }
        if (num == m - 1) {
          forbool = true;
          memory = i;
          break;  
        }
      }  
      if (forbool) break;
    }
    for (int j = 0; j < 100; j++) {
      dp[memory + 1][j] = -1;
      if (dp[memory][j] == 0) {
        dp[memory][j] = -1; 
      }  
    } 
    memory = memory + 2;
    for (int j = 0; j < 100; j++) {
      dp[memory][j] = 1;  
    }
    forbool = false;
    memory++;
    for (int i = memory; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        if ((i - memory) % 2 == 1) {
          dp[i][j] = 1;     
        }    
        else {
          if (i == memory) {
            if (j % 2 == 0) {
              dp[i][j] = -1;
              nun++;  
            }  
            else {
              dp[i][j] = 1;  
            }
          }
          else {
            dp[i][j] = dp[i - 2][j] * -1;   
            if (dp[i][j] == -1) {
              nun++;  
            }
          }
        }
        if (nun == n - 1) {
          forbool = true;
          break;  
        }
      }  
      if (forbool) break;
    }
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        if (dp[i][j] == 0) {
          dp[i][j] = 1;  
        }  
      }  
    }
  }
  cout << "100 100" << endl;
  string ans1 = "#";
  string ans2 = ".";
  if (a > b) {
    swap(ans1, ans2);  
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (dp[i][j] == 1) {
        cout << ans1;
      }  
      else {
        cout << ans2;  
      }
    }  
    cout << endl;
  }
}