#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string S;
  cin >> S;

  if(S=="zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
  }else if(S.size()==26){
    char y;
    for(int i=S.size()-1;i>0;i--){
      if(S.at(i) > S.at(i-1)){
        y=S.at(i-1);
        S=S.substr(0,i-1);
        break;
      }
    }
    int A[26]={0};
    REP(i,S.size()){
      A[S.at(i)-'a']++;
    }

    FOR(i,y-'a'+1,26){
      if(A[i]==0){
        char x = i+'a';
        cout << S+x << endl;
        break;
      }
    }
  }else{
    int A[26]={0};
    REP(i,S.size()){
      A[S.at(i)-'a']++;
    }

    REP(i,26){
      if(A[i]==0){
        char x = i+'a';
        cout << S+x << endl;
        break;
      }
    }
  }
}