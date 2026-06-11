#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    int l;
    l=s.size();
    string s2;
    int s3,ans=1000;
    rep(i,l-2){
        s2=s.substr(i,3);
        //s4=s2;
        s3=atoi(s2.c_str());
        ans=min(ans,abs(753-s3));
        //cout << s2 << endl;
    }

    cout << ans << endl;
    

    return 0;
}