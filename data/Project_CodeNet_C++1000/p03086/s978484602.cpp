#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;

    int ans = 0;
    int cnt = 0;
    bool f = false;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T'){
            cnt++;
            ans = max(ans, cnt);
            f = true;
        
        }else if(f){
            cnt = 0;
            f = false;
        }
    }

    cout<<ans<<endl;
    return 0;
}