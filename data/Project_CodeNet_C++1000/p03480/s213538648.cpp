#include<iostream>
#include<string>
using namespace std;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int main(){
  string s;
  int mi,num,n;
  cin >> s;
  n = s.size();
  mi = n;
  for(int i=0;i<n-1;i++){
    if(s[i]!=s[i+1]){
      mi = min(mi,max(i+1,n-i-1));
    }
  }
  cout << mi << endl;
}
