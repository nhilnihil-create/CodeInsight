#include <iostream>
#include <string>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;

int main(){
    string s;
    cin >> s;
    int num=0, ans=0;

    rep(i, s.size()){
        bool can = false;
        if(s[i]=='A')can = true;
        if(s[i]=='C')can = true;
        if(s[i]=='G')can = true;
        if(s[i]=='T')can = true;

        if(can){
            num++;
            if(num>ans) ans = num;
        }
        else num = 0;
    }

    cout << ans << endl;

    return 0;
}