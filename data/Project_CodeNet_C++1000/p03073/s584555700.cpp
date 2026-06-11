#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
    string s;
    cin >> s;
    int cunt=0;
  for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        cunt++;
        }
    }
        cout << cunt << endl;
        return 0;
    }