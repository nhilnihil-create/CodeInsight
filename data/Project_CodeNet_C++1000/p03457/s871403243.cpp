#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    cin >> N;
    vector<int> t(N);
    vector<int> x(N);
    vector<int> y(N);
    rep(i,N)cin>>t[i]>>x[i]>>y[i];

    int now_x = 0;
    int now_y = 0;
    int now_t = 0;

    int dis_t = 0;
    int dis_x = 0;
    int dis_y = 0;

    for(int i=0; i<N; i++){
        dis_t = t[i] - now_t;
        dis_x = abs(x[i] - now_x);
        dis_y = abs(y[i] - now_y);
        if(dis_x + dis_y > dis_t){
            cout << "No" << endl;
            return 0;
        }

        if((dis_t - dis_x + dis_y) % 2 == 1 ){
            cout << "No" << endl;
            return 0;
        }

        now_x = x[i];
        now_y = y[i];
        now_t = t[i];
    }

    cout << "Yes" << endl;
    return 0;

}