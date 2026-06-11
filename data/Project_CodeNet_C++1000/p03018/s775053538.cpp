#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s;

int main(void){
    cin >> s;
    lli n = s.size();
    string t = "";
    lli j = 0;
    while(j < n){
        if(s[j] == 'A') t+='A', j++;
        if(s[j] == 'B'){
            if(j+1 < n && s[j+1] == 'C') t+='D', j+=2;
            else t+='#', j++;
        }
        if(s[j] == 'C') t+='#', j++;
    }
    //cout << t << endl;
    j = 0;
    lli ac = 0;
    lli ans = 0;
    n = t.size();
    while(j < n){
        if(j < n && t[j] == '#') j++;
        else{
            while(j < n && t[j] != '#'){
                if(j < n && t[j] == 'A'){
                    ac++;
                    j++;
                }else if(j < n && t[j] == 'D'){
                    ans+=ac;
                    j++;
                }
            }
            ac = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
