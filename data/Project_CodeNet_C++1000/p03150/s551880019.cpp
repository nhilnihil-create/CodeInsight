#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,ssub;
    cin >> s;
    int i=0,count=0;
    for(i=0;i<8;i++){
        ssub=s;
        ssub=ssub.erase(i,s.size()-7);
        //cout << ssub << endl;
        if(ssub=="keyence")count++;
    }
    if(count!=0)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}