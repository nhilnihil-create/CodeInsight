#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) FOR(i,0,n)
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

string s;
int a[3];

int main(){
  cin>>s;

  rep(i,s.size()){
    a[s[i]-'a']++;
  }

  if(abs(a[0]-a[1])<2&&abs(a[0]-a[2])<2&&abs(a[1]-a[2])<2){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

  return 0;
}
