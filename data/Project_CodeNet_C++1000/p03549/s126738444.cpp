#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n,m;
cin>>n>>m;
int count=1900*m+100*(n-m);
//cout<<count<<endl;
cout<<count*pow(2,m)<<endl;


  return 0;
}
