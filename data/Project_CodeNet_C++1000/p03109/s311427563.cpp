#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.at(5)=='0'&&((s.at(6)=='1')||(s.at(6)=='2')||(s.at(6)=='3')||(s.at(6)=='4'))) cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}