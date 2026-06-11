#include<iostream>
#include<string>
using namespace std;
int main(void){
    string s;
    cin >> s;
    string ws = "2017";
    auto pos = s.find(ws);
    if(pos != string::npos){
        s.replace(pos,ws.length(),"2018");
    }
    cout << s;
}