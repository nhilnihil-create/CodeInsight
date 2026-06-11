#include <bits/stdc++.h>
using namespace std;
int n,k;
string str;
int main() {
    cin>>n>>k>>str;
    if (str[k-1]=='A') str[k-1]='a';
    if (str[k-1]=='B') str[k-1]='b';
    if (str[k-1]=='C') str[k-1]='c';
    cout<<str<<'\n';
}