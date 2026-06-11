/*
　　　　　　 ＿＿
　　　　　／＞　　 フ
　　　　　|   _　 _l  
　 　　　／` ミ＿x ノ   Zzz..
　　 　 /　 　 　 |   コード見ちゃだめ！！
　　　 /　 ヽ　　  ﾉ
　 　 │　　|　|  |   
　／￣|　　 |　|  |
　| (￣ヽ＿_ヽ_)_ _)
　＼二つ
*/

#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) reverse((a).begin(),(a).end())
#define REP(i, n) for(int i = 0; i < n; i++)
const int MOD = 1e9+7;
typedef long long ll;
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
  string s;
  cin>>s;
  vector<char>a(s.length());
  for(int i=0;i<s.length();i++){
    a[i]=s[i];
  }
  int right=s.length()-1;
  int left=0;
  int count=0;
  while(right-left>=1){
    if(a[right]==a[left]){
      right--;
      left++;
    }else if(a[right]=='x'){
      right--;
      count++;
    }else if(a[left]=='x'){
      left++;
      count++;
    }else break;
  }
  if(right-left>=1) cout<<"-1"<<endl;
  else cout<<count<<endl;
}