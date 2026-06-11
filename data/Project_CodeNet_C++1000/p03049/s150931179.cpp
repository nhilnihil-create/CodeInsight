#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<string> s(N+10);
    int Acnt = 0;
    int Bcnt = 0;
    int both = 0;

    for(int i=0; i<N; i++){
        cin>>s[i];
        int l = s[i].size()-1;
        if(s[i][l] == 'A' && s[i][0] == 'B') both++;
        else{
            if(s[i][l] == 'A') Acnt++;
            if(s[i][0] == 'B') Bcnt++;
        }
    }

    int ans = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<(int)s[i].size(); j++){
            string tmp = "";
            for(int k=j; (k<j+2 && k<(int)s[i].size()); k++) tmp += s[i][k];
            if(tmp == "AB") ans++;
        }
    }

    if(Acnt == 0 && Bcnt == 0) ans += max(both-1,0);
    else ans += both + min(Acnt,Bcnt);
    cout<<ans<<endl;

    return 0;
}