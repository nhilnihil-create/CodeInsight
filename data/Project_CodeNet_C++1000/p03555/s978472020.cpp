#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str1,str2;
    cin>>str1>>str2;
    if(str1[0]==str2[2]&&str1[2]==str2[0]&&str1[1]==str2[1])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}