#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;++i){
    cin >> s[i];
  }
  int ab_num=0;
  int a,b;
  a=0;
  b=0;
  int ba=0;
  for(int i=0;i<n;++i){
    int siz=s[i].size();
    if(s[i][0]=='B' && s[i][siz-1]!='A') b++;
    if(s[i][siz-1]=='A' && s[i][0]!='B') a++;
    if(s[i][0]=='B' && s[i][siz-1]=='A') ba++;
    for(int j=1;j<s[i].size();++j){
      if(s[i][j-1]=='A' && s[i][j]=='B'){
        ab_num++;
      }
    }
  }
  int ans=ab_num;
  if(ba==0){
    ans+=min(b,a);
  }else if(ba!=0 && a+b>0){
    ans+=ba+min(a,b);
  }else if(a+b==0){
    ans+=(ba-1);
  }
  cout << ans << endl;
  return 0;
}
