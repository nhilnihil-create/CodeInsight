#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
    cin>>s;
    if(s.size()<=25){
        int a[26]={};
        for(int i=0;i<s.size();i++)a[s[i]-'a']=1;
        cout<<s;
        for(int i=0;i<26;i++){
            if(a[i]==0){
                cout<<char('a'+i);
                return 0;
            }
        }
    }
    for(int i=s.size()-1;i;i--){
        if(s[i-1]<s[i]){
            for(int j=0;j<i-1;j++)cout<<s[j];
            for(int j=s.size();j>=i;j--){
                if(s[i-1]<s[j]){
                    cout<<s[j];
                    return 0;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}
