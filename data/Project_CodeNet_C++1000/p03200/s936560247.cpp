#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int countW=0,countB=0;
    for(int i=0; i<s.size(); i++){
        if(s.at(i)=='W') countW++;
        if(s.at(i)=='B') countB++;
    }

    long long int ans=0;
    for(int i=0; i<s.size(); i++){
        if(s.at(i)=='W') countW--;
        else if(s.at(i)=='B'){
            ans+=countW;
            countB--;
        }
        if(countB==0 || countW==0) break;
    }

    cout << ans << endl;
}
