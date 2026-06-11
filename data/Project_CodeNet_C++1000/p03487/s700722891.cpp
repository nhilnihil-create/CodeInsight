#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    map<int,int> mp;
    for(int i=0;i<n;i++) mp[a[i]]++;
    int ans=0;
    for(auto p:mp){
        int b=p.first;
        int c=p.second;
        if(c<b) ans+=c;
        else ans+=c-b;
    }
    cout << ans << endl;
}