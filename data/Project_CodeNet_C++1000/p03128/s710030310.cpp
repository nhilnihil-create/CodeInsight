#include<bits/stdc++.h>
using namespace std;
string chk(string s,int a){
    char c = '0'+a;
    s = s+c;
    sort(s.begin(),s.end(),greater<char>());
    return s;
}
int main(){
    int n,m;
    cin >> n >> m;
    int a[m];
    for(int i=0;i<m;i++)cin >> a[i];
    int mat[10] = {-1,2,5,5,4,5,6,3,7,6};
    vector<string>dp(n+1);
    for(int i=0;i<n;i++){
        if(i!=0 && dp[i]=="")continue;
        for(int j=0;j<m;j++){
            if(i+mat[a[j]] > n)continue;
            string tmp = chk(dp[i],a[j]);
            if(tmp.length() > dp[i+mat[a[j]]].length()){
                dp[i+mat[a[j]]] = tmp;
            }else if(tmp.length() == dp[i+mat[a[j]]].length() && tmp > dp[i+mat[a[j]]]){
                dp[i+mat[a[j]]] = tmp;
            }
        }
    }
    cout << dp[n]<<endl;
}