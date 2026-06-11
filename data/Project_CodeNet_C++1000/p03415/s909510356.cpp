#include<iostream>
using namespace std;
int main(void){
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >>s3;
    s4.push_back(s1[0]);
    s4.push_back(s2[1]);
    s4.push_back(s3[2]);
    cout << s4;
}