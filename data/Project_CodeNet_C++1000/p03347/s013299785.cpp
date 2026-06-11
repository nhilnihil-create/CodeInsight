#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  
  if(a[0]!=0){
    cout<<-1<<endl;
    return 0;
  }
  ll res=0;
  rep(i,n-1){
    if(a[i+1]==a[i]+1) res++;
    else if(a[i+1]<=a[i]) res+=a[i+1];
    else{
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<res<<endl;
}