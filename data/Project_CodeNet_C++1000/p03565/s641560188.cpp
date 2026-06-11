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
    string scopy=s;
    vector<string> anscand;
    for(int i=s.length()-t.length();i>=0;i--){
        s=scopy;
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
            anscand.push_back(s);            
        }
        
    }
    sort(anscand.begin(),anscand.end());
    if(!anscand.empty()){
        cout<<anscand[0]<<endl;
    }else{
        cout<<"UNRESTORABLE"<<endl;
    }
    
    return 0;
}