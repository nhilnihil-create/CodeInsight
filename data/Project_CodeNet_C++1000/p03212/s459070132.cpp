#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

bool is_sgs(int x){
    map<int, int> mp;
    while(x){
        int d = x%10;
        mp[d]++;
        x /= 10;
    }
    if(mp[3] > 0 && mp[5] > 0 && mp[7] > 0){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    int n;
    cin >> n;

    queue<int> sgs;
    sgs.push(3);
    sgs.push(5);
    sgs.push(7);

    int cnt = 0;
    int flag = 1;
    while(flag){
        int tmp = sgs.front();
        sgs.pop();
        if(tmp <= n){
            if(is_sgs(tmp)){
                cnt++;
            }
            sgs.push(tmp*10 + 3);
            sgs.push(tmp*10 + 5);
            sgs.push(tmp*10 + 7);
        }
        else{
            flag = 0;
        }
    }

    cout << cnt << endl;
    return 0;
}