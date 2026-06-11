#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,ans=0;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i=0,k,l;i<m;i++){
        cin >> k >> l;
        a.at(k-1)++;
        a.at(l)--;
    }
    for(int i=0,l=0;i<n;i++){
        l+=a.at(i);
        if(l==m) ans++;
    }
    cout << ans << endl;
    return 0;
}