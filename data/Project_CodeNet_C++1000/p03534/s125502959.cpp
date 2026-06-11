#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  string str;cin>>str;
  int cnt[3]={};
  for(int i=0;i<str.size();i++)
    cnt[str[i]-'a']++;
  int ma=0;
  ma=max(ma,abs(cnt[0]-cnt[1]));
  ma=max(ma,abs(cnt[1]-cnt[2]));
  ma=max(ma,abs(cnt[0]-cnt[2]));
  if(ma<=1)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}
