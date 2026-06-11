#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){

    string s;
    cin>>s;

    int w; cin>>w;
    string ans ="";
    for(int i =0;i<s.length();i+=w){
        ans+=s[i];
    }
    cout<<ans<<endl;

}
