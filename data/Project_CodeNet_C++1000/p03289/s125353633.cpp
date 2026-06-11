#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin>>s;
    int cnt=0;
    if(s[0]!='A'){
        cout<<"WA"<<endl;
        return 0;
    }else{
        for(int i=2;i<s.size()-1;i++){
            if(isupper(s[i])){
                cnt+=1;
            }

        }
        if(cnt!=1){
            cout<<"WA"<<endl;
            return 0;
        }
    }
    int cnt2=0;
    rep(i,s.size()){
        if(isupper(s[i]))cnt2+=0;
        else cnt2+=1;

    }
    if(cnt2==s.size()-2)cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
}