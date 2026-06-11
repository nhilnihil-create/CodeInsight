#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define REP1(i,n) for(int i=1;i<=(int)(n);i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)


int main(){
  int N,M,ans=0;
  string temp;
  vector<string> str;
  vector<int> num;

  cin >> N;
  REP(i,N){
    cin >> temp;
    if(i==0){
      str.push_back(temp);
      num.push_back(1);
    }
    
    else{
      REP(j,str.size()){
	if(temp==str.at(j)){
	  num.at(j)++;
	  break;
	}
	else if(j==str.size()-1){
	  str.push_back(temp);
	  num.push_back(1);
	  break;
	}
      }
    }
  }
  
  cin >>M;
  REP(i,M){
    cin >> temp;
    REP(j,str.size()){
      if(temp==str.at(j))num.at(j)--;
    }
  }

  REP(i,num.size())ans=max(num.at(i),ans);
  cout << ans;
}
