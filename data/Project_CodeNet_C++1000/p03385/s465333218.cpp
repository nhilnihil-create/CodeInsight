#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  if(s=="abc" || s=="acb" || s=="bac" || s=="bca" || s=="cab" || s=="cba"){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}