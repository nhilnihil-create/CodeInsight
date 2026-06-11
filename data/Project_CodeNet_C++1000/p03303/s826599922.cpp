#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s;
    int w;
    cin>>s>>w;
    string ans;
    int i=0;
    while(i<s.size()){
        ans+=s[i];
        i+=w;
    }
    cout<<ans<<endl;
}