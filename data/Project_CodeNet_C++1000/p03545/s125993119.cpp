#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;


void solve(std::string S){
  char op[2] = {'+', '-'};
  int ret = S[0]-'0';
  for(int i=0; i<2; i++) {
    int x = ret;
    if(op[i]=='+') ret += (S[1]-'0');
    else ret -= (S[1]-'0');
    for(int j=0; j<2; j++) {
      int x = ret;
      if(op[j]=='+') ret += (S[2]-'0');
      else ret -= (S[2]-'0');
      for(int k=0; k<2; k++) {
	int x = ret;
	if(op[k]=='+') ret+= (S[3]-'0');
	else ret -= (S[3]-'0');
	if(ret == 7) {
	  std::cout << S[0]<<op[i]<<S[1]<<op[j]<<S[2]<<op[k]<<S[3]<<"=7"<< std::endl;
	  return;
	}
	ret = x;
      }
      ret = x;
    }
    ret = x;
  }
}

int main(){
    std::string ABCD;
    std::cin >> ABCD;
    solve(ABCD);
    return 0;
}
