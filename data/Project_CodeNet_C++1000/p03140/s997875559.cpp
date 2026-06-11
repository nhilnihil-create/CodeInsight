#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]&&b[i]!=c[i]&&c[i]!=a[i])ans+=2;
        else if(a[i]==b[i]&&b[i]==c[i]&&c[i]==a[i]);
        else ans++;
    }
    cout<<ans<<endl;
}
