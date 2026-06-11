#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s;
    cin>>s;

    if(s[0]!='A'){
        cout<<"WA"<<"\n";
        return 0;
    }
    size_t l=s.length();
    int cnt=0;
    for(int i=1;i<l;i++){
        if(isupper(s[i])){
            if(i==1 || i==l-1 || s[i]!='C'){
                cout<<"WA"<<"\n";
                return 0;
            }
            else cnt++;
        }
    }
    if(cnt==1) cout<<"AC"<<"\n";
    else cout<<"WA"<<"\n";
    return 0;
}