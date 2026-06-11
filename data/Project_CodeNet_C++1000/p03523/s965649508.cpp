#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  string SS[20] = { "KIHBR","AKIHBR","KIHABR","KIHBAR","KIHBRA","AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA","AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABARA" };
  string ans="NO";
  rep(i,20){
    if(S==SS[i]){
      ans="YES";
      break;
    }
  }
  cout<<ans<<endl;
}