#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string s;
  cin >> s;
  int n=s.size();
  int ans=abs(((int)(s[0]-'0')*100+(int)(s[1]-'0')*10+(int)(s[2]-'0'))-753);
  for(int i=0; i<n-2; i++){
    int a=(int)(s[i]-'0');
    int b=(int)(s[i+1]-'0');
    int c=(int)(s[i+2]-'0');
    int d=(a*100+b*10+c);
    ans=min(ans,abs(753-d));
  }
  cout << ans << endl;
}
            
    

