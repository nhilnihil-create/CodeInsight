#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();

    vector<vector<int>>a(n+1,vector<int>(m+1));
    for(int i=1; i<=n ; ++i){
        for(int j=1; j<=m; ++j){
           if(s[i-1] == t[j-1])
                a[i][j] = a[i-1][j-1]+1;
           else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
        }
    }

    string ans = "";
    int x = n, y = m;

    while(y!=0 && x!=0){
            if(a[x-1][y] == a[x][y])
             --x;
            else if(a[x][y-1] == a[x][y])
                --y;
            else{
                ans = t[y-1]+ans;
                --x;
                --y;
            }
    }
    cout<<ans;
}
