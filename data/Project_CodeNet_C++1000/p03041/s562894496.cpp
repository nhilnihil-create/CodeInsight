#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int conv='A'-'a';

    s[k-1]-=conv;

    cout<<s<<endl;
}
