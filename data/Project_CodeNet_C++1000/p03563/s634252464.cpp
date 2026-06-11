#include<bits/stdc++.h>
using namespace std;
int main(){
  int R=-1, G=4501;
  cin >> R >> G;
  if(R<0||4500<G) cout << "入力エラー(制約 : 0≦R, G≦4500)" << endl;  
  else cout << G*2.0 -R << endl;
}
