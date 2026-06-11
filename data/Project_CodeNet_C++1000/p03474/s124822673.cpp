#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

int main(){

 int a,b; string s;
  cin>>a>>b;
  cin>>s;

  if(s[a] == '-')
  {
       for(int i=0;i<s.length();i++)
       {
            int number = s[i]-'0';
        if(number >=0 && number<10)
           continue;
        else if(i!= a){
        cout<<"No"<<endl;
        return 0; }
       }
  }
  else{
    cout<<"No"<<endl;
    return 0; }

  cout<<"Yes"<<endl;

return 0;
}
