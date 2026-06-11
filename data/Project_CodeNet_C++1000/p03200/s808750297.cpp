#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
string S;
cin>>S;
ll ans=0,count=0,W=0;
rep(i,S.size()){
  if(S[i]=='W'){ W++; count+=i;}

}
rep(i,W){
  ans+=i;
}
cout<<count-ans<<endl;

  return 0;
}
