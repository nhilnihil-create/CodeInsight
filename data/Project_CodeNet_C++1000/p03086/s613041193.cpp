#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long


int main(){
    string s;
    cin >> s;

    int count=0, ans=0;
    for(int i=0; i<(int)s.length(); ++i){
        count=0;
        if(s[i]=='A' || s[i]=='G' || s[i]=='C' || s[i] =='T'){
            int j=i;
            while(j<(int)s.length()){
                if(s[j]=='A' || s[j]=='G' || s[j]=='C' || s[j] =='T'){
                    count++;
                    j++;
                }
                else
                    break;
            }
            ans = max(ans, count);
        }
    }
    cout << ans;
}