#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  
  auto f = [](string S){
    int tmp = 0;
    for(char c: S){
      int num = c - '0';
      tmp += num;
    }
    return tmp;
  };
  int ans = 0;
  for(int i = 0; i <= N; i++){
    string s = to_string(i);
    int tmp = f(s);
    if(tmp >= A && tmp <= B){
      ans+=i;
    }
  }
  cout << ans << endl;
}



