#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)

using namespace std;

int main() {

    int b,cnt=0,cnt1=0; cin>>b;

    string s; cin>>s;

    for(int i=0;i<s.length();i++){
        if(s[i] == 'R') cnt++;
        else if(s[i] == 'B') cnt1++;
     }

     if(cnt > cnt1) cout<<"Yes"<<endl;
     else
        cout<<"No"<<endl;

    return 0;
}
