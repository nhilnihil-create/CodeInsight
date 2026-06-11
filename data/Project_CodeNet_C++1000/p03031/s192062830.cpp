#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
int A,B,C,K,N,M,X,Y,cnt;

int main(){
  cin >> N >> M;
  vector<bitset<10>> switches(M);
  rep(i,M){
    int k;
    cin >> k;
    bitset<10> s;
    rep(j,k){
      int pos;
      cin >> pos;
      pos--;
      s.set(pos);
    }
    switches.at(i) = s;
  }
  auto p = getValues<int>(M);
  
  for(int i=0;i<(1<<N);i++){
    bitset<10> s(i);
    int r = 0;
    rep(j,M){
      auto v = switches.at(j) & s;
      int num = v.count();
      if(num%2==p.at(j)){
        r++;
      }
    }
    if(r==M){
      cnt++;
    }
  }
  print(cnt);
}
