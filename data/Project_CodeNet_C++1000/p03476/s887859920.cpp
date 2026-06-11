#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

vector<bool> flag_prime(ll max){
    vector<bool> flag(max,true);

    flag[0] = false;
    flag[1] = false;
    for(int i = 2; i*i < max+1; i++){
        if(flag[i]){
            for(int j = 2; i*j < max+1; j++) flag[i*j] = false;
        }
    }

    return flag;
}

vector<int> num_prime(int max){
    vector<int> num;
    vector<bool> flag = flag_prime(max);

    for(int i = 0; i < max+1; i++){
        if(flag[i]) num.push_back(i);
    }

    return num;
}

int main(){
    int max = 1e6;
    vector<bool> flag = flag_prime(max);
    vector<int> cnt(max);
    int now = 0;
    for(int i = 0; i < max; i++){
        if(flag[i] && flag[(i+1)/2]) now++;
        cnt[i] = now;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        l--;
        cout << cnt[r]-cnt[l] << endl;
    }
    return 0;
}