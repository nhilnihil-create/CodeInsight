#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
int main(){
int a[3];
rep(i,3){
  cin>>a[i];
}
sort(a,a+3);

cout<<a[0]*a[1]/2<<endl;

  return 0;
}
