/*
      author  : nishi5451
      created : 14.08.2020 19:33:29
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s,t;
    cin >> s >> t;
    int len = s.size();
    for(int i=0; i<len; i++){
        string rot;
        rot=s.substr(i,len);
        if(rot==t){
            cout << "Yes" << endl;
            return 0;
        }
        s.push_back(s[i]);
    }
    cout << "No" << endl;
    return 0;
}