#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>> data(H,vector<char>(W));
    for (int i=0;i<H;i++) {
        for (int j=0;j<W;j++) {
            cin >> data.at(i).at(j);
        }
    }
    for (int i=0;i<H;i++) {
        for (int j=0;j<W;j++) {
            int count=0;
            if (data.at(i).at(j) == '.') {
                for (int k=-1;k<2;k++) {
                    for (int l=-1;l<2;l++) {
                        if (i+k<0 || i+k>=H || j+l<0 || j+l>=W) {
                            continue;
                        }
                        else if (data.at(i+k).at(j+l) == '#') {
                            count++;
                        }
                    }
                
                }
                cout << count;
            }
            else {
                cout << '#';
            }
            
            
        }
        cout << endl;
    }
    
}