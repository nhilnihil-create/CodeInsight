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

ll calculateDivNums(ll tg){
	ll ans = 0;
	for(ll a=1;a*a<=tg;a++){
      if(tg%a!=0){
        continue;
      }
      ans++;
      if(tg!=a*a){
        ans++;
      }
    }
  return ans;
 }   

string S;
int A,B,C,K,N, cnt;

int main(){
  cin >> A >> B >> K;
  stack<int> s;
  rep2(i,min(A,B)){
    if(A%i==0 && B%i==0){
      s.push(i);
    }
  }
  rep(i,K-1){
    s.pop();
  }
  printl(s.top());
}
