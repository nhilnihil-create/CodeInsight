#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s=="zyxwvutsrqponmlkjihgfedcba")cout<<-1<<endl;
    else if(s.size()<26){
        for(int i=0;i<26;i++){
            bool ok=true;
            for(int j=0;j<s.size();j++){
                if(s[j]-'a'==i)ok=false;
            }
            if(ok){
                cout<<s+(char)(i+'a')<<endl;
                break;
            }
        }
    }else{
        vector<bool> u(26,false);
        for(int i=s.size()-1;i>=0;i--){
            for(int j=s[i]-'a'+1;j<26;j++){
                if(u[j]){
                    for(int k=0;k<i;k++){
                        cout<<s[k];
                    }
                    cout<<(char)('a'+j)<<endl;
                    return 0;
                }
            }
            u[s[i]-'a']=true;
        }
    }
}