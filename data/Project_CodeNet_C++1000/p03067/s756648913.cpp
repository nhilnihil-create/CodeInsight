#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a<c && c<b){
    cout << "Yes" << endl;
  }else if(b<c && c<a){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
return 0;
}