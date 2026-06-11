#include<iostream>
using namespace std;
int main(){
    string s;
    int w;
    cin>>s>>w;
    for(int i=0;w*i<s.size();i++)cout<<s[w*i];
    cout<<endl;
    return 0;
}