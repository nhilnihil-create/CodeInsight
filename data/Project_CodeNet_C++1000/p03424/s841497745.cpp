#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,cnt=0;
    string s;
    cin >> n;
    for(int i=1; i<=n; i++){
       cin >> s;
       if(s=="Y"){
         cout << "Four" << endl;
         break;
       }
     cnt++;
    }
    if(cnt==n) cout << "Three" << endl;
    return 0;
}