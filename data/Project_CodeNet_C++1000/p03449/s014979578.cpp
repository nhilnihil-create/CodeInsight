#include<bits/stdc++.h>
#define ll long long
#define P pair<int ,int>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> vec(2 ,vector<int>(n));
    for(int i=0;i<n;i++) cin >> vec[0][i];
    for(int i=0;i<n;i++) cin >> vec[1][i];

    int ans = 0;
    for(int down = 0 ; down < n ; down++){
        int sum = 0;
        int tate = 0;
        for(int j=0;j<n;j++){
            if(j == down){
                sum += vec[tate][j];
                tate++;
                sum += vec[tate][j];
            }else {
                sum += vec[tate][j];
            }
        }ans = max (ans ,sum);
    }

    cout << ans << endl;
}
