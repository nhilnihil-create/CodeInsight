#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int H,W;
    cin >> H >>W;
    vector<vector<int>> a(H);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int b;
            cin >> b;
            a[i].push_back(b);
        }
    }
    vector<tuple<int,int,int,int>> ans;
    for(int i=0;i<H;i++){
        for(int j=0;j<W-1;j++){
            if(a[i][j] %2 == 1){
                ans.emplace_back(i+1,j+1,i+1,j+2);
                a[i][j+1]++;
            }
        }
    }
    for(int i=0;i<H-1;i++){
        if(a[i][W-1] %2==1){
            ans.emplace_back(i+1,W,i+2,W);
            a[i+1][W-1]++;
        }
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << get<0>(ans[i]) << " "<<get<1>(ans[i]) <<" "<<get<2>(ans[i])<<" "<<get<3>(ans[i])<<endl;
    }

    return 0;
}