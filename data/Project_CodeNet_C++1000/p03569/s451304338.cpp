#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;


int main(){
  string S;cin >> S;
  int N = S.size();
  string T = "";
  vector<int> P(1,0);
  for(int i = 0;i < N;i++){
    if(S[i] != 'x'){
      T.push_back(S[i]);
      P.push_back(i);
    }
  }
  P.push_back(N);
  int m = T.size();
  //cout << m << endl;
  for(int i = 1;i <= m/2;i++){
    if(m % 2 == 0){
      if(T[m/2-i] != T[m/2+i-1]){
      cout << -1 << endl;
      return 0;
      }
    }else{
      if(T[m/2-i] != T[m/2+i]){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  /*for(int i = 0;i <= m;i++){
    cout << P[i] << ' ';
  }
  cout << endl;*/
  int ans = 0;
  //if(m % 2 == 1){
    int a = 1;
    //cout << m << endl;
    int lbase,rbase;
    if(m % 2 == 0){
      lbase = P[m/2]+1;rbase = P[m/2+1]+1;
      //cout << m/2+1 << endl;
    }else{
      a++;
      lbase = P[m/2+1]+1;rbase = P[m/2+1]+1;
    }
    bool lfrag = 0,rfrag = 0;
    int l = 0,r = 0;
    S = 'a' + S + 'a';
    //cout << S << endl;
    for(int i = 1;i <= m/2+a;i++){
      int l = 0,r = 0;
      int j = 0;
      //cout << lbase << ' ' << rbase << ' ' << l << ' ' << r << ' ' << ">>";
      while(rbase <= N){
        rbase++;
        if(S[rbase+j] != 'x'){
          break;
        }
        r++;
        
      }
      j = 0;
      while(lbase >= 0){
        lbase--;
        if(S[lbase-j] != 'x'){
          break;
        }
        l++;
        
      }
      //cout << lbase << ' ' << rbase << ' ' << l << ' ' << r <<  endl;
      ans += abs(r-l);
    }
  //}
  cout << ans << endl;
}
