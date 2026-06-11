#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int count=0,a=0,b=0,c=0;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
      if(s[i]=='A'&&s[i+1]=='B'){
        count++;
      }
    }
    if(s[0]=='B'&&s[s.size()-1]=='A'){
      c++;
    }
    else if(s[0]=='B'){
      b++;
    }
    else if(s[s.size()-1]=='A'){
      a++;
    }
  }
  int answer=count;
  if(c==0){
    answer+=min(a,b);
  }
  else if(a+b>0){
    answer+=min(a,b)+c;
  }
  else{
    answer+=c-1;
  }
  cout<<answer<<endl;
}