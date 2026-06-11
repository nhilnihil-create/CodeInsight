#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;
int main(){
   vector<int> a(3);
   rep(i,3) cin>>a[i];
   sort(a.begin(),a.end());
   cout<<a[0]*a[1]/2<<endl;
   return 0;
}
