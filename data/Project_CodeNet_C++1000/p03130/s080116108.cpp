#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;
#define mp make_pair;
#define pb push_back;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int used[4]={};
vector<int> g[4];

int dfs(int index){
  int far=0;
  used[index]=1;
  for(int i=0; i < g[index].size(); i++){
    if(!used[g[index][i]]){
      far = max(far, dfs(g[index][i])+1);      
    }
  }
  return far;
}



int main(){
  int a,b;
  for(int i=0; i<3; i++){
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  int far=0;
  for(int i=0; i<4; i++){
    for(int j=0;j<4; j++){
      used[j]=0;
    }
    far = max(dfs(i),far);
    //    cout << far << endl;
  }
  if(far==3){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  
  return 0;

}
