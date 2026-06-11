#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int h,w,n;
  cin>>h>>w>>n;
  int sr,sc;
  cin>>sr>>sc;
  sr--; sc--;
  string s,t;
  cin>>s>>t;
  
  vector<vector<int>> kosu1(2,vector<int>(n+1));
  vector<vector<int>> kosu2(2,vector<int>(n+1));
  rep(i,n){
    if(s[i]=='L') kosu1[0][i+1]=-1;
    if(s[i]=='R') kosu1[0][i+1]=1;
    if(s[i]=='U') kosu1[1][i+1]=-1;
    if(s[i]=='D') kosu1[1][i+1]=1;
    if(t[i]=='L') kosu2[0][i+1]=-1;
    if(t[i]=='R') kosu2[0][i+1]=1;
    if(t[i]=='U') kosu2[1][i+1]=-1;
    if(t[i]=='D') kosu2[1][i+1]=1;
  }
  
  int p1=sr,p2=sr,q1=sc,q2=sc;
  rep(i,n+1){
    if(kosu1[0][i]==1) q2++;
    if(kosu1[0][i]==-1) q1--;
    if(kosu1[1][i]==1) p2++;
    if(kosu1[1][i]==-1) p1--;
    if(p1<0||p2>=h||q1<0||q2>=w){
      cout<<"NO"<<endl;
      return 0;
    }
    if(kosu2[0][i]==-1&&q2>0) q2--;
    if(kosu2[0][i]==1&&q1<w-1) q1++;
    if(kosu2[1][i]==-1&&p2>0) p2--;
    if(kosu2[1][i]==1&&p1<h-1) p1++;
  }
  cout<<"YES"<<endl;
}