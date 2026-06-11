#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,S="";
    long long int A=0,ans=0;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(i!=s.size()-1 && s[i]=='B' && s[i+1]=='C'){
            S += 'D';
            ++i;
        }else{
            S += s[i];
        }
    }

    for(int i=0;i<S.size();i++){
        if(S[i]=='A'){
            A++;
        }else if(S[i]=='D'){
            ans += A;
        }else{
            A = 0;
        }
    }

    cout << ans << endl;
}