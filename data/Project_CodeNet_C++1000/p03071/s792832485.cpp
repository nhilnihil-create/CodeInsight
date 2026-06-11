#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()





int main(){
  
  int a,b;
  cin>>a>>b;
  
  if (a==b){
    cout<<2*a<<endl;
  }
  else {
    cout<<2*max(a,b)-1<<endl;
  }


}










