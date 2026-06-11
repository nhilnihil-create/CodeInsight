#include<iostream>
#include<regex>
using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<(regex_match(s,regex(R"(A?KIHA?BA?RA?)"))?"YES":"NO")<<endl;
    return 0;
}