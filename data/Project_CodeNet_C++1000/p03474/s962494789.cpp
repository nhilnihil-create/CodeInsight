#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    string s;
    cin >> a >> b >> s;
    if(s[a]!='-'){
        cout << "No" << endl;
        return 0;
    }
    sort(s.begin(),s.end());
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='-')cnt++;
    }
    if(cnt!=1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}