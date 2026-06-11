#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    int ab=0,a=0,b=0,aob=0;
    for(int i = 0; i < n; i++) {
        string s;cin >> s;
        if(s[0]=='B') b++;
        if(s[s.size()-1]=='A') a++;
        if(s[0]=='B' && s[s.size()-1]=='A') aob++;

        for(int i = 0; i < s.size()-1; i++) {
            if(s[i]=='A' && s[i+1]=='B') ab++;
        }
    }

    if(aob==a && a==b && a>0){
        ab += a-1;
    }
    else ab += min(a,b);

    cout << ab << endl;

    return 0;
}