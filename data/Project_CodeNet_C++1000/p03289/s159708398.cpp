#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    string s;
    cin>>s;
    int len=s.size();
    int cnt=0;
    bool flag=true;;
    if(s[0]!='A'){
        flag=false;
    }
    for(int i=1;i<len;i++){
        if(isupper(s[i])){
            if(i==1||i==len-1||s[i]!='C'){
                flag=false;
            }
            cnt++;
        }
    }
    if(cnt!=1||!flag)cout<<"WA"<<endl;
    else cout<<"AC"<<endl;
}