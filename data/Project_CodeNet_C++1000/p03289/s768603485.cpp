#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    bool correct=true;
    int cntC=0;
    rep(i,0,S.size()){
        char c=S.at(i);
        if(i==0){
            if(c!='A') correct=false;
        }
        else if(c>='A' && c<='Z'){
            if(c=='C'){
                if(i>1 && i<S.size()-1) cntC++;
            }
            else correct=false;
        }
    }
    if(cntC!=1) correct=false;

    if(correct) cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
}