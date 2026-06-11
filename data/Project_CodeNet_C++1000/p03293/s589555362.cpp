#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
    string s,t;
    cin>>s>>t;
    int len=s.size();
    rep(i,len){
        s=s[len-1]+s.substr(0,len-1);
        if (s==t){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}