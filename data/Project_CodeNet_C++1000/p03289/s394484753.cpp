#include<bits/stdc++.h>
using namespace std;



int main(void){
    string s;
    cin>>s;
    int judge=0;
    int count=0;
    if(s[0]=='A') judge++;
    for(int i=2;i<s.size()-1;i++){
        if(s[i]=='C') count++;
    }
    if(count==1) judge++;
    int count2=0;
    for(int i=0;i<s.size();i++){
        if('a'<=s[i]&&s[i]<='z') count2++;
    }
    if(count2==s.size()-2) judge++;
    if(judge==3){
        cout<<"AC"<<endl;
    }else{
        cout<<"WA"<<endl;
    }
    return 0;
}

