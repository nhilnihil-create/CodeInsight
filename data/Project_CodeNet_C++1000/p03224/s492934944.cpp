#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
int main(){
  int n;cin>>n;
  bool flag=false;
  int ans[5000][5000]={};
  int a,b;
  n*=2;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0&&(n/i==i+1)){
      a=n/i;b=i;
      flag=true;
      int num=n/i;
      int now=1;
      for(int j=0;j<i;j++){
	for(int k=j;k<i;k++){
	  ans[j][k]=now;
	  ans[k+1][j]=now;
	  now++;
	}
      }
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
    cout<<a<<endl;
    for(int i=0;i<a;i++){
      cout<<b<<" ";
      for(int j=0;j<b;j++){
	cout<<ans[i][j];
	if(j!=b-1)
	  cout<<" ";
      }
    cout<<endl;
  }

  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
