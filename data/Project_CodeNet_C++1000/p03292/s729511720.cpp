#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;


int main(){
   vector<int> a(3);
   rep(i,3) cin>>a[i];
   sort(a.begin(),a.end());
   cout<<a[2]-a[0]<<endl;
   return 0;
}

   
