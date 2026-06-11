#include <iostream>
#include <string>
using namespace std;
int main(){
  int N;
  cin>>N;
  string s[10000];
  int a,b,c;
  a=0;
  b=0;
  c=0;
  long long answer=0;
  for(int i=0;i<N;i++){
    cin>>s[i];
    for(int j=0;j<s[i].size()-1;j++){
      if(s[i][j]=='A'&&s[i][j+1]=='B') answer++;
    }
    if(s[i][0]=='B') b++;
    if(s[i][s[i].size()-1]=='A') a++;
    if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A') c++;
  }
  answer+=min(a,b);
  if(a==b&&b==c&&a!=0) answer--;
  cout<<answer<<endl;
  
  return 0;
}