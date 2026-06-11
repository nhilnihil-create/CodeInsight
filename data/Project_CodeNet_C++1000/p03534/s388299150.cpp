
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
//#include <algorithm>
#include<set>
#include <limits>
#include<iomanip>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007
int main(void){
  string s;
  cin >> s;
  vector<int> snum(3,0);
  rep(i,s.size()){
    snum[s[i]-'a']+=1;
  }
  int minsnum=min(snum[0],snum[1]);
  minsnum=min(snum[2],minsnum);
  snum[0]-=minsnum;
  snum[1]-=minsnum;
  snum[2]-=minsnum;
    if(snum[0]>=2||snum[1]>=2||snum[2]>=2){
      cout<<"NO"<<endl;
    }else{
      cout<<"YES"<<endl;
    }
  return 0;
}