#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    int y=stoi(s.substr(0,4)),m=stoi(s.substr(5,2));
    if(y*12+m>24232) cout<<"TBD"<<endl;
    else cout<<"Heisei"<<endl;

    return 0;
}