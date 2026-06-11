#include <bits/stdc++.h>
using namespace std;
int main(){
    string S,ans;
    cin >>S;
    if(S=="A"){
        ans="T";
    }
    if(S=="T"){
        ans="A";
    }
    if(S=="G"){
        ans="C";
    }
    if(S=="C"){
        ans="G";
    }
    cout <<ans<<endl;
}
