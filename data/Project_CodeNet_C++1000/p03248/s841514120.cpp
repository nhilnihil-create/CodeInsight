#include <bits/stdc++.h>
using namespace std;
int dp[100001];
char a[100002];
vector<int> b[100001];
int n;

void f(int k,int v){
    if(k==n)return;
    if(a[k]=='1'){
        b[v].push_back(k+1);
        f(k+1,k+1);
    }
    else{
        b[v].push_back(k+1);
        f(k+1,v);
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>a+1;
    n=strlen(a+1);
    int i;
    if(a[n]=='1' || a[1]=='0'){
        cout<<-1;
        return 0;
    }
    for(i=1 ; i<n ; i++){
        if(a[i]!=a[n-i]){
            cout<<-1;
            return 0;
        }

    }

    f(1,1);
    for(i=1 ; i<=n ; i++){
        for(auto &j: b[i]){
            cout<<i<<" "<<j<<"\n";
        }
    }
    return 0;
}
