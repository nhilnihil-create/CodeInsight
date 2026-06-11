#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    bool flag=true;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(i==0){
            if(s[i]!='A') flag=false;
        }else if(i>=2&&i<=s.length()-2){
            if(s[i]=='C') cnt++;
        }else if(s[i]>='A'&&s[i]<='Z') flag=false;
    }
    if(cnt!=1) flag=false;
    if(flag) cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
}
