#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') s[i]='9';
        else s[i]='1';
    }
    cout<<s<<endl;

}

