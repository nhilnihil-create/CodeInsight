#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<=n)mp[a[i]]++;
        else ans++;
    }
    for(int i=1;i<=n;i++){
        if(mp[i]>i)ans+=(mp[i]-i);
        else if(mp[i]<i)ans+=mp[i];
    }
    cout << ans;
}