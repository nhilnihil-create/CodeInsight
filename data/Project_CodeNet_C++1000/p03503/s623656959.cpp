#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> f(n,vector<int>(10));
    vector<vector<int>> p(n, vector<int>(11));
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            cin >> f.at(i).at(j);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<11; j++){
            cin >> p.at(i).at(j);
        }
    }
    int ans = -pow(10,9);
    for(int i=1; i<(1<<10); i++){
        vector<int> open(10,0);
        for(int j=0; j<10; j++){
            if(i & (1<<j)) open.at(j)=1;
        }
        int gain=0;
        for(int j=0; j<n; j++){
            //お店j
            int dub=0;
            for(int k=0; k<10; k++){
                //お店jとの被り時間数を考える
                dub += f.at(j).at(k)*open.at(k);
            }
            gain += p.at(j).at(dub);
        }
        ans = max(ans, gain);
    }
    cout << ans << endl;
}