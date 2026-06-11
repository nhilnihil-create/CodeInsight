#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    long long cnt=0,ans=0;
    cin >> S;
    //bbw -> bwb -> wbb
    //あるwの左にあるbの数を数える。これを全てのw似たいし行う
    for(int i=0;i<S.size();i++){
        if(S.at(i)=='B') cnt++;
        if(S.at(i)=='W') ans += cnt;
    }
    cout << ans << endl;
    return 0;
}