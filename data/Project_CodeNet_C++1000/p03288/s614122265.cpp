#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;
int main(){
    int n;cin >> n;
    if(n<1200)
      cout<<"ABC"<<endl;
    else if(n<2800)
      cout<<"ARC"<<endl;
    else
      cout<<"AGC"<<endl;
  return 0;
}
