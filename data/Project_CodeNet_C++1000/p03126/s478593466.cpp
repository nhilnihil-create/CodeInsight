#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(m+1);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int> a(k);
        for(int j=0;j<k;j++){
            cin>>a.at(j);
            cnt.at(a.at(j))++;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(cnt.at(i)==n)
        ans++;
    }
    cout<<ans<<endl;
}