#include<bits/stdc++.h>
using namespace std;
#define LOD (24) // LOD : Length of Day
int main(){
  int M = 0;
  cin >> M;
  if(M<1) cout << "入力エラー(制約:1≦M,M≦23)" << endl;
  else cout << LOD * 2 - M << endl;
}
