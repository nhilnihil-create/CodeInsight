#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  string s;
  int xy[2];
  cin>>s>>xy[0]>>xy[1];
  int j=0;
  vector<int> d[2];
  d[0].push_back(0);
  rep(i,s.size()){
    if(s[i]=='T'){
      j^=1;
      d[j].push_back(0);
    }
    else d[j].back()++;
  }
  rep(i,2){
    vector<bool> v1(16005,false);
    v1[8003]=true;
    rep(k,d[i].size()){
      if(k==0){
	if(i==0){
	  v1[8003+d[0][0]]=true;
	  continue;
	}
	else{
	  v1[8003]=true;
	}
      }
      int x=d[i][k];
      vector<bool> v2(16005,false);
      rep(j,16005){
	if(v1[j]){
	  v2[j+x]=true;
	  v2[j-x]=true;
	}
      }
      v1=v2;
    }
    if(!v1[xy[i]+8003]){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}

