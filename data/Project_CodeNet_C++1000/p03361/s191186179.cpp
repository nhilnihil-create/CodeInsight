#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h+2,vector<char>(w+2));
    for(int i=1; i<h+1; i++){
        for(int j=1; j<w+1; j++){
            cin >> s.at(i).at(j);
        }
    }

    string ans="Yes";
    for(int i=1; i<h+1; i++){
        for(int j=1; j<w+1; j++){
            if(s.at(i).at(j)=='#'){
                if(s.at(i-1).at(j)=='.'&&s.at(i+1).at(j)=='.'&&s.at(i).at(j-1)=='.'&&s.at(i).at(j+1)=='.'){
                    ans="No";
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}