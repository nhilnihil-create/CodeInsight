#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;
    int many0 = 0 ,many1 = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') many0++;
        else many1++;
    }
    cout << min(many0 ,many1) * 2 << endl;
}