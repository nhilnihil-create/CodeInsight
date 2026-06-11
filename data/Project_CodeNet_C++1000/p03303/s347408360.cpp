#include<iostream>
#include<string>
using namespace std;
string s,ds;
int main(int argc, char const *argv[]){
    int len,l,i;
    while(getline(cin,s)){
        cin>>l;
        ds="";
        len=s.length();
        for(i=0;i<len;++i){
            if(i%l==0){
                ds+=s[i];
            }
        }
        cout<<ds<<endl;
    }
    return 0;
}