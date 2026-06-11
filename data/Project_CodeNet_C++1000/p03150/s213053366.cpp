#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans = "keyence";
    int pos=0;
    //try at the beginning
    if(s.substr(0,7)==ans)pos=1;
    //try at the end
    if(s.substr((int)s.size()-7,7)==ans)pos=1;
    //try the other possible way
    for(int i=1;i<=6;i++){
        if((s.substr(0,i)==ans.substr(0,i))&&(s.substr((int)s.size()-(7-i),7-i)==ans.substr(i,7-i)))pos=1;
    }
    if(pos==1)cout<<"YES";
    else cout<<"NO";
}