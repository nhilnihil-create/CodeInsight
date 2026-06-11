#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s,g;
    cin>>s>>g;
    int fi=s.find(g[0]);
    string k=s.substr(fi,s.size())+s.substr(0,fi);
    cout<<((g==k)?"Yes":"No");
  	return 0;
}