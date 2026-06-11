#include<iostream>

using namespace std;
int main(){

    char s[100000]={'3'};
    cin>>s;
    int a=0,b=0;

    for(int i=0;i<100000;i++){
        if(i%2==0){
            if(s[i]=='1'){
                a++;
            }
        }
        else{
            if(s[i]=='0'){
                a++;
            }
        }
    }

    for(int i=0;i<100000;i++){
        if(i%2==0){
            if(s[i]=='0'){
                b++;
            }
        }
        else{
            if(s[i]=='1'){
                b++;
            }
        }
    }

    if(a<b)cout<<a<<endl;
    else{cout<<b<<endl;}

    return 0;
}