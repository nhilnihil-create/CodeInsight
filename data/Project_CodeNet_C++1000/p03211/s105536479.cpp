#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans=1e9;
    int tmp;
    for(int i=0;i<S.length()-2;i++){
        tmp=(S[i]-'0')*100+(S[i+1]-'0')*10+(S[i+2]-'0');
        ans=min(ans,abs(tmp-753));
    }
    cout << ans << endl;
}