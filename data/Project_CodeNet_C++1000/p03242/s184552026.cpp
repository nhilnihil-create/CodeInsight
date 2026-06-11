#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s;
    cin >> s;
    for(auto &i: s){
        if(i == '9')i = '1';
        else if(i == '1')i = '9';
    }
    cout << s << endl;
}