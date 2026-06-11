#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
char s[N];
int n,m;
char x[N],y[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    cin>>(s+1);
    for(int i=0;i<m;i++) cin>>x[i]>>y[i];
    int l = 0, r = n + 1;
    for(int i=m-1;i>=0;i--){
        if(y[i]=='L'){
            if(x[i]==s[l+1]) l++;
            if(x[i]==s[r]) r++;
        }
        else{
            if(x[i]==s[r-1]) r--;
            if(x[i]==s[l]) l--;
        }
        if(l+1>=r) break;
//        cout<<l<<' '<<r<<endl;
    }
    cout<<max(r-l-1,0)<<endl;
}
