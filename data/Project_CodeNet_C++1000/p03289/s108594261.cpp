#include <iostream>
using namespace std;
int main(void){
    string s;
    cin>>s;
    if (s[0]!='A'){
        cout<<"WA";
        exit(0);
    }
    int inC=0;
    for (int i=2;i<s.size()-1;i++){
        if (s[i]=='C'){
            inC++;
        }
    }
    if (inC!=1){
        cout<<"WA";
        exit(0);
    }
    for (int i=0;i<s.size();i++){
        if (s[i]!='A' &s[i]!='C'& s[i]!=tolower(s[i])){
            cout<<"WA";
            exit(0);
        }
    }
    cout<<"AC";
    
}
