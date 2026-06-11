#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int a,b,c,d;
    a=s.at(0)-'0';
    b=s.at(1)-'0';
    c=s.at(2)-'0';
    d=s.at(3)-'0';
    if(a+b+c+d == 7){
        cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl;
        return 0;
    }
    if(a+b+c-d == 7){
        cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl;
        return 0;
    }
    if(a+b-c+d == 7){
        cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl;
        return 0;
    }
    if(a-b+c+d == 7){
        cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl;
        return 0;
    }
    if(a-b-c+d == 7){
        cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl;
        return 0;
    }
    if(a-b+c-d == 7){
        cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl;
        return 0;
    }
    if(a+b-c-d == 7){
        cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl;
        return 0;
    }
    if(a-b-c-d == 7){
        cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl;
        return 0;
    }
}