#include<iostream>
using namespace std;
int main(){
    char s1,s2;
    cin>>s1>>s2;
    s1<s2?cout<<"<":(s1==s2)?cout<<"=":cout<<">";
}