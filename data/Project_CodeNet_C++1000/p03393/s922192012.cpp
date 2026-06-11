#include<iostream>
using namespace std;
string S;
bool a[26];
int main(){
    cin>>S;
    if(S=="zyxwvutsrqponmlkjihgfedcba"){cout<<-1<<endl;return 0;}
    for(int i=0;i<S.size();i++)a[S[i]-'a']=true;

    if(S.size()!=26)for(int i=0;i<26;i++)if(a[i]==false){cout<<S+char('a'+i)<<endl;return 0;}
    for(int i=0;i<S.size();i++){
        for(int c=S[S.size()-1-i]-'a';c<26;c++){
            if(a[c]==false){
                S[S.size()-1-i]=char('a'+c);
                cout<<S.substr(0,S.size()-i)<<endl;
                return 0;
            }
        }
        a[S[S.size()-1-i]-'a']=false;
    }
    return 0;
}