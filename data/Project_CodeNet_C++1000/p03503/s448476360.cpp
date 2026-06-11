#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<vector<bool>> shop(n);
    vector<vector<int>> mon(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            int tmp;
            cin >> tmp;
            shop[i].push_back(tmp);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            int p;
            cin >> p;
            mon[i].push_back(p);
        }
    }

    ll sum = -mod;

    for(int bit=1; bit<(1<<10); bit++){
        vector<bool> much(10,false);
        ll can = 0;
        for(int i=0; i<10; i++){
            if(bit&(1<<i)) much[i] = true;
        }
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < 10; j++){
                if(shop[i][j] && much[j]) cnt++;
            }
            can += mon[i][cnt];
        }

        if(sum < can) sum = can; 
    }

    cout << sum << endl;
}