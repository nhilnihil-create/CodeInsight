#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    char s1,s2;
    cin>>s1>>s2;
    if((s1-'A')>(s2-'A'))cout<<">"<<endl;
    else if((s1-'A')<(s2-'A'))cout<<"<"<<endl;
    else cout<<"="<<endl;

    return 0;
}