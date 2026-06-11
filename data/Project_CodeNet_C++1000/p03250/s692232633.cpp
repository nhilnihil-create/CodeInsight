#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int A,B,C;
   cin>>A>>B>>C;
   vector<int> data{A,B,C};
   sort(data.begin(),data.end());
   int ans=data[2]*10+data[1]+data[0];
   cout<<ans<<endl;
   
}