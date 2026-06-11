#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);

    const int dx[] = {1,1,0,-1,-1,-1,0,+1};
    const int dy[] = {0,1,1,1,0,-1,-1,-1};

    for(int i=0; i<h; ++i)
        cin >> s[i];

    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(s[i][j]=='#'){
                cout << "#";
                continue;
            }

            int ans=0;
            for(int k=0; k<8; ++k){
                int nx = i+dx[k];
                int ny = j+dy[k];

                if(nx<0 || nx>=h || ny<0 || ny>=w)
                    continue;
                
                if(s[nx][ny] == '#')
                    ans++;
            }
            cout << ans;
        }
        cout << endl;
    }
}