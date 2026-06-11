#include <bits/stdc++.h>
using namespace std;
string s;
int x;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++)if(s[i]=='x')x++;
    cout<<(x<8?"YES\n":"NO\n");
}