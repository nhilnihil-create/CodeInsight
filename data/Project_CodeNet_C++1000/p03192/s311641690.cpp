#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    cout<<count_if(s.begin(),s.end(),[](char& c){return c=='2';})<<"\n";
}