#include<bits/stdc++.h>
using namespace std;

const string akiba="AKIHABARA";
int main(){
    string s;
    cin>>s;
    int p=0;
    for(int i=0;i<akiba.size();i++){
        if(p==s.size() || s[p]!=akiba[i]){
            if(akiba[i]=='A') continue;
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else p++;
    }
    cout<<(p==s.size() ? "YES" : "NO")<<endl;
    return 0;
}