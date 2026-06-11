#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
string S;
cin>>S;
map<char,int> m;
rep(i,3)
m[S[i]]++;

if(m['a']==1&&m['b']==1&&m['c']==1)
cout<<"Yes"<<endl;
else
{
  cout<<"No"<<endl;
}



  return 0;
}
