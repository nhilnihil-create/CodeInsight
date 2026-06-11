
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    int time=0;
    pair<int,int> loc(0,0);
    for(int i=0; i<n; i++){
        int t, x, y;
        cin >> t >> x >> y;
        //時間内に行けるところより遠くにいる場合
        if(t-time < abs(x-loc.first)+abs(y-loc.second)){
            cout << "No" << endl;
            return 0;
        }
        //偶奇が合わない場所にはいけない
        else if((t-time)%2==0 && (abs(x-loc.first)+abs(y-loc.second))%2 == 1){
            cout << "No" << endl;
            return 0;
        }
        else if((t-time)%2==1 && (abs(x-loc.first)+abs(y-loc.second))%2 == 0){
            cout << "No" << endl;
            return 0;
        }

        loc.first = x;
        loc.second = y;
        time = t;
    }
    cout << "Yes" << endl;
}