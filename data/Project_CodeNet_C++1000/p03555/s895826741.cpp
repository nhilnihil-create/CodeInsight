#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    char c=s1.at(0);
    s1.at(0)=s1.at(2);
    s1.at(2)=c;
    if(s1==s2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
