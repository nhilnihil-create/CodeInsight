#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,Q;
  string s;
  cin >> N >> Q;
  cin >> s;
    vector<int> sum(N,0);
 froop1(1,N){
    if(s[i - 1] =='A' && s[i] == 'C') sum.at(i) = 1;
    sum.at(i) += sum.at(i - 1);
  }
  
  froop1(0,Q){
    int r,l;
    cin >> r >> l;
    cout << sum.at(l - 1) - sum.at(r - 1) << endl;
  }
  

return 0;
  }