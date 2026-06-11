#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            a++;
        }else if(s[i]=='b'){
            b++;
        }else{
            c++;
        }
    }
    if(a==1&b==1&c==1){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}