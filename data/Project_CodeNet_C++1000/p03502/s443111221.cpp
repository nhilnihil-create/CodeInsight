#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s = to_string(n);
    int sum=0;
    for(int i=0;i<s.length();i++)sum+=(s[i]-'0');
    if(n%sum==0)cout << "Yes";
    else cout << "No";
}