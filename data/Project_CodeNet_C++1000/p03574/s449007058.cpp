/*
      author  : nishi5451
      created : 14.08.2020 15:26:06
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s;
    string dots;
    rep(i,w+2) dots.push_back('.');
    s.push_back(dots);
    rep(i,h){
        string tmp;
        cin >> tmp;
        string a;
        a.push_back('.');
        a += tmp;
        a.push_back('.');
        s.push_back(a);
    }
    s.push_back(dots);
    //rep(i,h+2) cout << s[i] << endl;

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(s[i][j]=='#') cout << "#";
            else{
                int now = 0;
                for(int ii=-1; ii<=1; ii++){
                    for(int jj=-1; jj<=1; jj++){
                        if(ii==0 && jj==0) continue;
                        if(s[i+ii][j+jj]=='#') now++;
                    }
                }
                cout << now;
            }
        }
        cout << endl;
    }
    return 0;
}