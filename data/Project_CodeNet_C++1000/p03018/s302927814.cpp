#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    string s;cin>>s;
    ll i=0;
    string ss="";
    while(i<s.size()){
        if(i!=s.size()-1&&s[i]=='B'&&s[i+1]=='C'){ss+='D';i++;}
        else if(s[i]=='B'||s[i]=='C')ss+='E';
        else ss+='A';
        i++;
    }
    ll cn=0,an=0;    
    for(int i=ss.size()-1;i>=0;i--){
        if(ss[i]=='E')cn=0;
        else if(ss[i]=='D')cn++;
        else if(ss[i]=='A')an+=cn;
    }
    cout<<an<<endl;
    
}





