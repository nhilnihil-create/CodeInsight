#include<bits/stdc++.h>
#define rep(i,n) for(int i= 0;i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
//vector<> vec(n);

int main(){
  int n=0;
  long long y=0,ans=0;

  cin >> n >> y;
  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      int z = n-i-j;
      	if(y==10000*i + 5000*j + 1000*z && z>=0){
        	cout << i << " " << j << " " << z << endl;
          	return 0;
        }
    }
  }
  
  cout << "-1 -1 -1" << endl;
  return 0;
}