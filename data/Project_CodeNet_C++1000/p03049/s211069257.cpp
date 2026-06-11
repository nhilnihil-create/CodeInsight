#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<string> v(n);
    int ans=0;
    rep(i, n){
        cin>>v[i];
        rep(j, v[i].size()-1){
            if(v[i][j] =='A' && v[i][j+1] =='B') ans++;
        }
    }
    int ba=0;
    int b=0;
    int a=0;
    rep(i, n){
        int l = v[i].size();
        if(v[i][0] == 'B' && v[i][l-1] == 'A'){
            ba++;
        }
        else if(v[i][0]=='B') b++;
        else if(v[i][l-1]=='A') a++;
    }
    ans+=max(0, ba-1);
    if(a>0 && ba!=0) {
        ans++;
        --a;
    }
    if(b>0 && ba!=0){
        ans++;
        --b;
    }
    ans+=min(a, b);
    cout<<ans<<endl;
    return 0;
}