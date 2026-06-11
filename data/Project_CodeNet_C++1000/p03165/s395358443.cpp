#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    string s = "" , t = "" , ans = "" ;
    cin >> s >> t ;
    int slen = s.size() , tlen = t.size() , lcs[slen+1][tlen+1] ;
    for(int i = 0 ; i <= slen ; i++)
        for(int j = 0 ; j <= tlen ; j++)
            lcs[i][j] = 0 ;
    for(int i = 1 ; i <= slen ; i++){
        for(int j = 1 ; j <= tlen ; j++){
            if(s[i-1] == t[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1 ;
            else lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]) ;
        }
    }
    int i = slen , j = tlen ;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]) ans += s[i-1] , i-- , j-- ;
        else if(lcs[i-1][j] > lcs[i][j-1]) i-- ;
        else j-- ;
    }
    for(int i = ans.size()-1 ; i >= 0 ; i--) 
        cout << ans[i] ;
}