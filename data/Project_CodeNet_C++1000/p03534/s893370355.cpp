#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
const int INF = 1 << 20;

typedef long long ll;




int main(){
  string s;
  cin >> s;
  int a[26] = {};
  REP(i,s.size()){
    a[s[i]%26]++;
  }
  
  int num = s.size()/3;
  if(s.size()%3 != 0)
    num++;
  int b = s.size()%3;
  if(b == 0)
    b = 3;
  int res = 0;
  bool f = 1;
  REP(i,26){
    if(a[i] > num){
      f = false;
    }
    else if(a[i] == num){
      res++;
    }
  }
  if(res > b){
    f = false;
  }
  
  if(f)
    cout <<  "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
