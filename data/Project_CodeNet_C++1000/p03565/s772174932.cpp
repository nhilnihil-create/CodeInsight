#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    int flag;
    char ans[(int)(s.length())];
    for(int j=0;j<(int)s.length();j++)ans[j]=s[j];
    if((int)s.length()-(int)t.length()>0){
    for(int i=0;i<(int)s.length()-(int)t.length();i++){
        flag=0;
        for(int j=0;j<(int)t.length();j++){
            if(s[(int)s.length()-1-i-j]!=t[(int)t.length()-1-j] && s[(int)s.length()-1-i-j]!='?'){
                flag++;
                break;
            }
        }
        if(flag==0){
            for(int j=0;j<(int)t.length();j++)if(ans[(int)s.length()-1-i-j]=='?')ans[(int)s.length()-1-i-j]=t[(int)t.length()-1-j];
            for(int j=0;j<(int)s.length();j++){
                if(ans[j]!='?')cout << ans[j];
                else cout << 'a';
            }
            return 0;
        }
    }
    }
    else if((int)s.length()-(int)t.length()==0){
        flag=0;
        for(int j=0;j<(int)t.length();j++){
            if(s[j]!=t[j] && s[j]!='?'){
                flag++;
                break;
            }
        }
        if(flag==0){
            for(int j=0;j<(int)t.length();j++)if(ans[j]=='?')ans[j]=t[j];
            for(int j=0;j<(int)s.length();j++)cout << ans[j];
            return 0;
        }
    }
    cout << "UNRESTORABLE";
}