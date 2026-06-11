#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool no=false;
    if(s[0]!='A'){
        no=true;
    }
    bool inside=false;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z'){
            if(!inside&&s[i]=='C'&&(i>=2&&i<=s.size()-2)){
                inside=true;
                continue;
            }
            else{  
                no=true;
                break;
            }
        }
    }
    if(no||!inside){
        cout<<"WA"<<endl;
    }
    else{
        cout<<"AC"<<endl;
    }
}