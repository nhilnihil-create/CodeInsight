#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    string s,t;
    cin>>s>>t;
    bool flag=false;
    for(int i=s.length()-t.length();i>=0;i--){
        flag=true;
        for(int j=0;j<t.length();j++){
            if(s[i+j]=='?') continue;
            if(t[j]!=s[i+j]) {
                flag=false;
                break;
            }
        }
        if(flag){
            for(int j=0;j<t.length();j++){
                s[i+j]=t[j];
            }
            for(int i=0;i<s.length();i++){
                if(s[i]=='?') s[i]='a';
            }
            break;
        }
    }
    if(flag){
        cout<<s<<endl;
    }else{
        cout<<"UNRESTORABLE"<<endl;
    }
    
    return 0;
}