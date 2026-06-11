#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);

    for(int i=0; i<n; ++i)
        cin >> s[i];
    
    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,1,0,-1};

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(s[i][j]=='#'){
                int count=0;
                for(int k=0; k<4; ++k){
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if(s[nx][ny]=='.')
                        count++;
                }

                if(count==4){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}
