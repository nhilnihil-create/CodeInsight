#include <iostream>
#include <string>

using namespace std;

int main(){
  int N;
  cin >> N;
  string s[N];
  for (int i = 0; i < N; i++){
    cin >> s[i];
  }

  int ans=0, acount=0, bcount=0, abcount=0;

  for (int i = 0; i < N; i++){
    if (s[i][0]=='B'){
      bcount++;
    }
    if (s[i][s[i].size()-1]=='A'){
      acount++;
    }
    if (s[i][0]=='B' && s[i][s[i].size()-1]=='A'){
      abcount++;
    }

    while(s[i].find("AB") != string::npos){
      int p = s[i].find("AB");
      s[i] = s[i].substr(p+2);
      ans++;
    }

  }

  if (acount < bcount) {
    ans += acount;
  }else{
    if (abcount != 0 && abcount==bcount && abcount==acount){
      ans += bcount - 1;
    }else{
      ans += bcount;
    }
  }
  
  printf("%d\n", ans);
  
}
