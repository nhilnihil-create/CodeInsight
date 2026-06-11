#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        if(s==t){
            cout<<"Yes"<<endl;
            return(0);
        }
        s.append(1,s[0]);
        s.erase(s.begin());
    }
    cout<<"No"<<endl;
    return(0);
}