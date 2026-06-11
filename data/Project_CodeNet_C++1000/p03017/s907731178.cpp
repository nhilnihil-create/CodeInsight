#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define lp(i,n) for(int i=0;i<(n);i++)
#define lps(i,j,n) for(int i=j;i<n;i++)

#define fordebug int hoge;cin>>hoge;

#define DEKAI 1000000007
#define floot10 cout<<fixed<<setprecision(15)
#define all(v) v.begin(),v.end()
double PI = acos(-1);

signed main(){
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  a--,b--,c--,d--;
  string s;
  cin>>s;
  string ans="Yes";
  
  //まずは、一人だけの時辿り着けるか考える
  //間に石が２個 並んでたら無理
  //a-c
  for(int i=a+1;i<=c;i++){
    if(s[i]=='#'&&s[i-1]=='#'){
      ans="No";
    }
  }

  //b-d
  for(int i=b+1;i<=d;i++){
    if(s[i]=='#'&&s[i-1]=='#'){
      ans="No";
    }
  }

  //追い越し必要？
  if(b<c&&d<c){
    //マスが3つ連続で空いてないとダメ！
    //追い越せるのはb-dの間
    bool check=false;
    for(int i=b+1;i<=d+1;i++){
      if(s[i-2]=='.'&&s[i-1]=='.'&&s[i]=='.'){
        check=true;
      }
    }
    if(check==false){//falseのままだったら、追い越せないのでNO
      ans="No";
    }
  }
  cout<<ans<<endl;
  return 0;
}
