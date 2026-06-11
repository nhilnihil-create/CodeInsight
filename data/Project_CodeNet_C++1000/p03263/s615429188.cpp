#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int H, W;
    cin >> H >> W;

    int a[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> a[i][j];
        }
    }

    vector<string> v;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(a[i][j] %2 == 0) continue;
            if(i == H-1 && j == W-1) continue;

            string ans = "";

            if(j != W-1){
                a[i][j+1]++;
                a[i][j]--;
                ans = to_string(i+1) + " " + to_string(j+1) + " " + to_string(i+1) + " " + to_string(j+2);
                v.push_back(ans);
                continue;
            }
            if(j == W-1){
                ans = to_string(i+1) + " " + to_string(j+1) + " " + to_string(i+2) + " " + to_string(j+1);
                v.push_back(ans);
                a[i][j]--;
                a[i+1][j]++;
                continue;
            }
        }
    }

    cout << v.size() << endl;
    for(auto l : v){
        cout << l << endl;
    }

    return 0;
}
