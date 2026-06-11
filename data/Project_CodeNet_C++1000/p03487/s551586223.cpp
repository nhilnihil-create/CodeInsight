#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
map <int, int> m;
int n;
cin>>n;
for(int i=0;i<n;i++){
int l;
cin>>l;
m[l]++;
}
int ans=0;
for(auto x : m){
if(x.first != x.second){
    if(x.first < x.second)ans+=x.second-x.first;
    else ans+=x.second;
}

}
cout<<ans<<endl;


}
