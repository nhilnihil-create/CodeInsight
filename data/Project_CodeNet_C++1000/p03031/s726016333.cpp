#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define birep(i,n) for (int i = 0; i < (1<<(n));i++)
#define isOne(bit,i) (bit & (1 << i))
using ll = long long;
using pint = pair<int, int>;

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
int N,M,cnt;

int main(){
  cin >> N >> M;
  vector<bitset<10>> swis(M);
  vector<int> ps(M);
  rep(i,M){
    int k; cin >> k;
    bitset<10> swi;
    rep(j,k){
      int s;
      cin >> s;
      bitset<10> b("0000000001");
      swi = swi | (b<<(s-1)); 
    }
    swis.at(i) = swi;
  }
  rep(i,M){
    cin >> ps.at(i);
  }

  birep(i,N){
    bitset<10> b(i);
    int ri = 0;
    rep(j,M){
      bitset<10> res = b & swis.at(j);
      if(res.count()%2==ps.at(j)){
        ri++;
      }
    }
    if(ri==M){
      cnt++;
    }
  }
  print(cnt);
}
