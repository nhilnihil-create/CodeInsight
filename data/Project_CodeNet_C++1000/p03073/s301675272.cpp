#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin>>s;
    vector<char>mihon1(s.size());
    vector<char>mihon2(s.size());
    int now=0;
    for(int i=0;i<s.size();i++){
        if(now==0){
            mihon1[i]='0';
            mihon2[i]='1';
            now+=1;
        }
        else{
            mihon1[i]='1';
            mihon2[i]='0';
            now-=1;
        }
    }
    int one=0; int two=0;
    rep(i,s.size()){
        if(s[i]!=mihon1[i]) one+=1;
        else if(s[i]!=mihon2[i])two+=1;
    }
    cout<<min(one,two)<<endl;
}

    

