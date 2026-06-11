#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int n = s.size(),ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int flag = 1;
            for(int k=i;k<=j;k++){
                if(!(s[k]=='A'||s[k]=='T'||s[k]=='G'||s[k]=='C')) flag = 0;
            }
            if(flag) ans = max(ans,j-i+1);
        }
    }
    cout << ans << endl;
}