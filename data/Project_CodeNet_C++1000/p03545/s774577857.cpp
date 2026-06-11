#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string k;
    cin>>k;
    int s[4];
    for(int i=0;i<4;i++){
        s[i]=k[i]-'0';
    }
    if(s[0]+s[1]+s[2]+s[3]==7)cout<<s[0]<<"+"<<s[1]<<"+"<<s[2]<<"+"<<s[3]<<"=7"<<endl;
    else if(s[0]-s[1]+s[2]+s[3]==7)cout<<s[0]<<"-"<<s[1]<<"+"<<s[2]<<"+"<<s[3]<<"=7"<<endl;
    else if(s[0]-s[1]-s[2]+s[3]==7)cout<<s[0]<<"-"<<s[1]<<"-"<<s[2]<<"+"<<s[3]<<"=7"<<endl;
    else if(s[0]-s[1]-s[2]-s[3]==7)cout<<s[0]<<"-"<<s[1]<<"-"<<s[2]<<"-"<<s[3]<<"=7"<<endl;
    else if(s[0]+s[1]-s[2]+s[3]==7)cout<<s[0]<<"+"<<s[1]<<"-"<<s[2]<<"+"<<s[3]<<"=7"<<endl;
    else if(s[0]+s[1]-s[2]-s[3]==7)cout<<s[0]<<"+"<<s[1]<<"-"<<s[2]<<"-"<<s[3]<<"=7"<<endl;
    else if(s[0]+s[1]+s[2]-s[3]==7)cout<<s[0]<<"+"<<s[1]<<"+"<<s[2]<<"-"<<s[3]<<"=7"<<endl;
    else if(s[0]-s[1]+s[2]-s[3]==7)cout<<s[0]<<"-"<<s[1]<<"+"<<s[2]<<"-"<<s[3]<<"=7"<<endl;
    return 0;
}