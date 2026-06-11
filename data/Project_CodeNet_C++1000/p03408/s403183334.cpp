#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,M;
  cin >> N;
  map<string,int> s;
  froop1(0,N){
    string s2;
    cin >> s2;
    if(s.count(s2)){
      s[s2]++;
    }else{
      s[s2] = 1;
    }
  }
  cin >> M;
  froop1(0,M){
   string s2;
    cin >> s2;
    if(s.count(s2)){
      s[s2]--;
    }else{
      s[s2] = -1;
  }
  }
  int max = 0;
  for(pair<string,int> p : s){
    if(p.second > max) max = p.second;
      
  }
  cout << max << endl;
return 0;
}