#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s,t;
    cin >> s >> t;
    vector<int> from(26,-1),to(26,-1);
    rep(i,int(s.size())){
        int a = s[i]-'a';
        int b = t[i]-'a';

        if(from[a]!=-1 || to[b]!=-1){
            if(from[a] != b || to[b] != a){
                cout << "No" << endl;
                return 0;
            }
        }else{
            from[a] = b;
            to[b] = a;
        }
    }   
    cout << "Yes" << endl;
    return 0;
}