#include <bits/stdc++.h>
using namespace std;
int main(){
    long long i, ans=0;
    bool anine=true;
    string n;
    cin >> n;
    for(i=0;i<n.size();i++){
        if(i==0) ans+=n[i]-'0'-1;
        else ans+=9;
        if(n[i]!='9' && i!=0) anine=false;
    }
    if(n.size()==1){
        ans=n[0]-'0';
    }
    if(anine && n.size()!=1){
        ans++;
    }
    cout << ans <<endl;
    return 0;
}
