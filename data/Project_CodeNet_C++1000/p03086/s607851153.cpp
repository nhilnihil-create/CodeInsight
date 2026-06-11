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
int N, cnt;

int main(){
  cin >> S;
  int len = 0;
  string t = "ACGT";
  rep(i,S.size()){
    if(S.at(i)== t.at(0) ||S.at(i)== t.at(1) ||S.at(i)== t.at(2) ||S.at(i)== t.at(3)){
      len++;
      cnt = max(len,cnt);
    }else{
      len=0;
    }
  }
  print(cnt);
}
