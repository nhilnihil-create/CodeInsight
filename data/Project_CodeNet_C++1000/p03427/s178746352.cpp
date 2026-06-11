#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++){
        sum+=s[i]-'0';
    }
    int s2=(s[0]-'0')+9*(s.size()-1);
    if(sum<s2)cout<<s2-1<<endl;
    else cout<<s2<<endl;
    return 0;
}