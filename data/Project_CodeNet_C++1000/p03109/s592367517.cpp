#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0;
    string s;
    //2019/04/30
    string ab = "56789";
    string ac = "321";
    cin>>s;
    if(s[5]=='1'){cout<<"TBD"; return 0;}
    if(s[5]=='0'){
        for(int i=0;i<5;i++){
                if(s[6]==ab[i]){cout<<"TBD"; return 0;}
        }
        for(int i=0;i<3;i++){
                if(s[6]==ac[i]){cout<<"Heisei"; return 0;}
        }
        if(s[6]=='4'){
            if(s[8]=='3' && s[9]=='1'){cout<<"TBD"; return 0;}
            else{cout<<"Heisei"; return 0;}
        }
    }
    return 0;
}
