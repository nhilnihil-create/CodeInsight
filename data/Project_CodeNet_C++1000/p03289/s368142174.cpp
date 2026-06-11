#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  string s;
  cin>>s;
  if(s[0]!='A'){
    cout<<"WA\n";
    return 0;
  }

  string a,b;
  for(int i=0;i<(int)s.size();i++){
    if(i<2||i>(int)s.size()-2){
      a+=s[i];
    }else{
      b+=s[i];
    }
    if(s[i]!='A'&&s[i]!='C'&&(s[i]<'a'||s[i]>'z')){
      cout<<"WA\n";
      return 0;
    }
  }
  //cout<<a<<"\n"<<b<<"\n";
  if(count(All(a),'C')>0){
    cout<<"WA\n";
    return 0;
  }
  if(count(All(b),'C')!=1){
    cout<<"WA\n";
    return 0;
  }

  cout<<"AC\n";


  return 0;
}
