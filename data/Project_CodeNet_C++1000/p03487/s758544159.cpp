#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,n,a[100010];
  map<int,int> mp;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  int ans=0;
  for(i=0;i<n;i++){
    if(mp[a[i]]==0){
      continue;
    }
    if(a[i]>mp[a[i]]){
      ans+=mp[a[i]];
    }
    else{
      ans+=mp[a[i]]-a[i];
    }
    mp[a[i]]=0;
  }
  cout << ans << endl;
}