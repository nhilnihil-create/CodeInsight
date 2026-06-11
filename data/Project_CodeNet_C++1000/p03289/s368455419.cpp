#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>> s;

    int C_cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(i == 0){
        if(s[0] != 'A'){
            cout<<"WA"<<endl;
            return 0;
        }
        }
        else if(1<i && i<s.size()-1 && s[i]=='C'){
            C_cnt++;
        }
        else if(s[i]-'a' < 0){
            //cout<<s[i]<<" : "<<s[i]-'a'<<endl;
            cout<<"WA"<<endl;
            return 0;
        }
    }

    if(C_cnt!=1){
        cout<<"WA"<<endl;
    }else{
        cout<<"AC"<<endl;
    }

    return 0;
}