// Wide Flip
#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    cin>>s;
    n=s.size();
    int ans=n/2;
    char c=s[ans];
    while(s[ans]==s[n-ans-1]&&s[ans]==c)ans++;
    cout<<ans<<endl;
}