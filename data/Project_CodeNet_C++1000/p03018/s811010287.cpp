#include <bits/stdc++.h>

using namespace std;


int main() {
        int count = 0;
        string s;
        cin >> s;
        long long int cnt=0,ans=0;
        //int last_ia=-1;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='A')++cnt;
            else if(s[i]=='B'){
                if(i+1<n&&s[i+1]=='C'){
                 ans+=cnt;
                  ++i;}
                else
                  cnt=0;
            }
          else cnt=0;
        }
     cout << ans;    
    
}