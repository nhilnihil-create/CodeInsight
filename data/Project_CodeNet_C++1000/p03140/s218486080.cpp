#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;string a,b,c;cin>>n>>a>>b>>c;
    int ans = 0;
    for(int i=0;i<a.length();i++){
        set<char> m;m.insert({a[i],b[i],c[i]});
        ans += m.size()-1;
    }
    cout<<ans;
}