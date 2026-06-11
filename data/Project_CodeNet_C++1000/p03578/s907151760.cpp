#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n;
    vector<int>d(n);
    for(int i=0; i<n; i++) cin>>d[i];
    cin>>m;
    vector<int> t(m);
    for(int i=0; i<m; i++) cin>>t[i];
    map <int,int> mpd,mpt;
    for(int i=0; i<n; i++) mpd[d[i]]++;
    for(int i=0; i<m; i++) mpt[t[i]]++;
    for(int i=0; i<m; i++) {
        if(mpt[t[i]] > mpd[t[i]]) {
            cout<<"NO"<<"\n";
            return 0;
        }
    }
    cout<<"YES"<<"\n";
}