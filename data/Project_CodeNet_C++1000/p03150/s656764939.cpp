#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    int sl=s.length();
    string ans="NO";
    rep(i,sl){
        for(int j=0; j<sl; ++j){
            string s1=s;
            s1.erase(i,j);
            if(s1=="keyence"){
                ans="YES";
            }
        }
    }
    cout<<ans<<endl;
}