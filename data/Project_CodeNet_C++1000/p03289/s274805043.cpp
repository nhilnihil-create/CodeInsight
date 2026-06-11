#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool check=true;
    if(s[0]=='A' && 'a'<=s[1] && s[1]<='z' && 'a'<=s[s.length()-1] && s[s.length()-1]<='z'){
        int cnt=0;
        for(int i=2;i<s.length()-1;i++){
            if(s[i]=='C') cnt++;
            else if(!('a'<=s[i] && s[i]<='z')){
                check=false;
                break;
            }
            if(cnt>=2){
                check=false;
                break;
            }
        }
        if(cnt==0) check=false;
    }
    else check=false;

    if(check) cout << "AC";
    else cout << "WA";
    cout << endl;
}