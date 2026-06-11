#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,q,i;
  string s;
  cin >> n >> q >> s;
  vector<int> a(n+1,0);
  a.at(0)=0;
  a.at(1)=0;
  for(i=2;i<=n;i++){
    if(s.at(i-2)=='A'&&s.at(i-1)=='C'){
      a.at(i)=a.at(i-1)+1;
    }else{
      a.at(i)=a.at(i-1);
    }
  }
  
  int l,r,m;
  for(i=0;i<q;i++){
    cin >> l >> r;
    if(l>1&&s.at(l-2)=='A'&&s.at(l-1)=='C'){
      m=1;
    }else{
      m=0;
    }
    cout << a.at(r)-a.at(l-1)-m << endl;
  }
}
    