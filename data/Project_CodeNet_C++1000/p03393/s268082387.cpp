#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    int end = s.size()-1;
    vector<bool> used(26,false);
    for(int i=0;i<n;i++){
        used[s[i]-'a']=true;
    }
    //足すか減るか
    if(n<26){
        for(int i=0;i<26;i++){
            if(!used[i]){
                cout<<s<<char('a'+i)<<endl;
                return 0;
            }
        }
    }
    else{
        while(s[end]<s[end-1]){
            if(end==1) break;
            end--;
        }
        
        if(end==1){
            if(s[0]!='z'){
                cout<<char(s[0]+1)<<endl;
                return 0;
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
        }else{
            char tmp = '~';
            for(int j=end;j<26;j++){
                if(s[end-1]<s[j]) tmp = min(tmp,s[j]);
            }
            cout<<s.substr(0,end-1)+tmp<<endl;
            return 0;
        }
        
    }
    
    return 0;
    
}