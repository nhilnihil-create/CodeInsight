#include <bits/stdc++.h>

using namespace std;

int main(int argc,char* argv[]){
  int a=0,b=0,c=0,d=0,N;
  for(int i=0;i<4;i++){
    cin >> N;
    if(N==1) a++;
    else if(N==4) b++;
    else if(N==7) c++;
    else if(N==9) d++;
  }
  if(a==1&&b==1&&c==1&&d==1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
