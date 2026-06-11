#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
int main(){
  string S, T;
  cin >> S >> T;
  vector<vector<int>> vec(2, vector<int>(26, 0));
  rep(i, S.size()){
    char s = S[i];
    int x;
    if(s=='a') x = 0;
    if(s=='b') x = 1;
    if(s=='c') x = 2;
    if(s=='d') x = 3;
    if(s=='e') x = 4;
    if(s=='f') x = 5;
    if(s=='g') x = 6;
    if(s=='h') x = 7;
    if(s=='i') x = 8;
    if(s=='j') x = 9;
    if(s=='k') x = 10;
    if(s=='l') x =11;
    if(s=='m') x =12;
    if(s=='n') x =13;
    if(s=='o') x =14;
    if(s=='p') x =15;
    if(s=='q') x =16;
    if(s=='r') x =17;
    if(s=='s') x =18;
    if(s=='t') x =19;
    if(s=='u') x =20;
    if(s=='v') x =21;
    if(s=='w') x =22;
    if(s=='x') x =23;
    if(s=='y') x =24;
    if(s=='z') x =25;
    vec[0][x]++;
  }
  rep(i, T.size()){
    char s = T[i];
    int x;
    if(s=='a') x = 0;
    if(s=='b') x = 1;
    if(s=='c') x = 2;
    if(s=='d') x = 3;
    if(s=='e') x = 4;
    if(s=='f') x = 5;
    if(s=='g') x = 6;
    if(s=='h') x = 7;
    if(s=='i') x = 8;
    if(s=='j') x = 9;
    if(s=='k') x = 10;
    if(s=='l') x =11;
    if(s=='m') x =12;
    if(s=='n') x =13;
    if(s=='o') x =14;
    if(s=='p') x =15;
    if(s=='q') x =16;
    if(s=='r') x =17;
    if(s=='s') x =18;
    if(s=='t') x =19;
    if(s=='u') x =20;
    if(s=='v') x =21;
    if(s=='w') x =22;
    if(s=='x') x =23;
    if(s=='y') x =24;
    if(s=='z') x =25;
    vec[1][x]++;
  }
  sort(vec[0].begin(), vec[0].end());
  sort(vec[1].begin(), vec[1].end());
  
  bool y = true;
  rep(i, 26){
    if(vec[0][i] != vec[1][i]){
      y = false;
      break;
    }
  }
  if(y) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
    


