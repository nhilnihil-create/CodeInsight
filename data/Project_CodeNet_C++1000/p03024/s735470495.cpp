#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18,MOD=1e9+7;
int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='o')cnt++;
    }
    if(s.length()==15){
        if(cnt>=8)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    else{
        //8-(15-(s.length())
        if(cnt>=(int)s.length()-7)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}