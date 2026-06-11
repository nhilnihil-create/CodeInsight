#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //good luck kittu!
    int n, q, l, r; string s;
    cin>>n>>q>>s;
    vector<int> a(n);
    for(int i = 0; i<n-1; i++){
        if(s[i]=='A' && s[i+1]=='C') a[i+1] = 1;
    }

    for(int i = 1; i<n; i++) a[i] += a[i-1];
    while(q--){
        cin>>l>>r;
        l--;
        r--;
        cout<<a[r]-a[l]<<"\n";
    }
    return 0;
}
