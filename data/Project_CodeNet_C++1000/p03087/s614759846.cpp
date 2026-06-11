#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> ans(n+1);
    for(int i=1;i<n;i++){
        if(s[i-1]=='A' && s[i]=='C'){
            ans[i]=ans[i-1]+1;
        }
        else{
            ans[i]=ans[i-1];
        }
    }
    ans[n]=ans[n-1];
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<ans[r-1]-ans[l-1]<<endl;
    }


return 0;
}
