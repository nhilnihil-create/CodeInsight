#include <bits/stdc++.h>
using namespace std;
string a,b;
int q,v,p,t;
unsigned long long dp[10000][10000];
int main(){
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);
getline(cin,a); getline(cin,b);
///cout<<f(a.size()-1,b.size()-1)<<'\n';
q=a.size(); v=b.size();
for(int n=1;n<=q;n++){
    for(int m=1;m<=v;m++){
        if(a[n-1]==b[m-1]) dp[n][m]=1+dp[n-1][m-1];
        else dp[n][m]=max(dp[n-1][m],dp[n][m-1]);
    }
}
p=q;
t=v;
string t="";
while(q>0&&v>0){
    if(a[q-1]==b[v-1]) {
        t=a[q-1]+t;
        q--;
        v--;
        continue;
    }
    if(dp[q-1][v]>=dp[q][v-1]){
        q--;
        continue;
    }
    v--;
}
cout<<t<<'\n';
///cout<<dp[p][t]<<'\n';
return 0;
}
