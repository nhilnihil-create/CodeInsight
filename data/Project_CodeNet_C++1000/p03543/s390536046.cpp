#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s; cin>>s;
    if(s[0]==s[1]&&s[1]==s[2]){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(s[1]==s[2]&&s[2]==s[3]){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    
}
