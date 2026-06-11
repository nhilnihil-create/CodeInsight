#include<iostream>
#include<string>
using namespace std;

int main(){
    string s; cin>>s;

    string ans="NO",t="keyence";
    for(int i=0;i<=7;i++){
        if(s.substr(0,i)==t.substr(0,i)&&s.substr(s.length()-7+i,7-i)==t.substr(i,7-i)) ans="YES";
    }
    cout<<ans<<endl;
}