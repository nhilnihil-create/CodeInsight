#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    set<char> setS;
    for(auto c:S) setS.insert(c);

    string ans="-1";
    if(setS.size()<26){
        rep(i,0,27){
            char c='a'+i;
            if(setS.count(c)==0){
                ans=S+c; 
                break;
            }
        }
    }else{
        bool escape=false;
        _rep(i,S.size()-1,0){
            char c=S.at(i),right_c=S.at(i)+1;
            setS.erase(c);
            for(char candi=c+1;candi<='z';candi++){
                if(!setS.count(candi)){
                ans=S.substr(0,i)+candi;
                escape=true;
                break;
                }
            }
            if(escape) break;
        }
    }

    cout<<ans<<endl;
}