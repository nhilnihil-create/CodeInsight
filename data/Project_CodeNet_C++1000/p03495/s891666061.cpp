#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n,k;
cin>>n>>k;
int a[n];
map<int,int>m;
rep(i,n){
cin>>a[i];
m[a[i]]++;
}
vector<pair<int,int>>x;

for(auto i:m){
x.push_back(make_pair(i.second,i.first));

}
sort(x.begin(),x.end());
int ans=0,q=0;
for(int i=x.size();i>k;i--){
ans+=x[q].first;
q++;
}
cout<<ans<<endl;
  return 0;
}
