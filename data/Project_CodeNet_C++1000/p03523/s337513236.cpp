#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
using namespace std;
using LL = long long;

int main(){
    string s;cin>>s;
    if(s[s.size()-1]!='A')s+='A';
    if(s[0]!='A')s.insert(s.begin(),'A');

    if(s=="AKIHABARA" || s=="AKIHBARA" || s=="AKIHABRA" || s=="AKIHBRA")cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}