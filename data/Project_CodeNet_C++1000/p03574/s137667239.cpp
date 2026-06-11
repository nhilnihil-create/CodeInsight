#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    vector<string> ans = s;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') ans[i][j] = '#';
            else{
                int count = 0;
                for(int ii = -1; ii <= 1; ii++){
                    for(int jj = -1; jj <= 1; jj++){
                        if(ii+i >= 0 && ii+i < h && jj+j >= 0 && jj+j < w && s[ii+i][jj+j] == '#') count++;
                    }
                }
                ans[i][j] = (char)(count+'0');
            }
        }
    }

    for(int i = 0; i < h; i++){
        cout << ans[i] << endl;
    }
    return 0;
}