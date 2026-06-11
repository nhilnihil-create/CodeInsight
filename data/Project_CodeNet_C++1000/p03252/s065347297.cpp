#include <bits/stdc++.h>
using namespace std;
int a[30]={},b[30]={};
int main() {
    string s,t;
    cin >> s >> t;
    for(int i=0;i<s.size();i++){
        int num1=s[i]-'a';
        int num2=t[i]-'a';
        a[num1]++,b[num2]++;
        if(a[num1]!=b[num2]){cout<<"No"; return 0;}
    }
    cout<<"Yes";
}
