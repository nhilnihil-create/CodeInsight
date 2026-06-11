#include<bits/stdc++.h>
using namespace std;
#define cp pair<char, char>
string S;
int N, Q;
int ans;
vector<cp> sp;

int main(){
    cin >> N >> Q >> S;
    ans = N;
    for(int i = 0; i < Q; i++){
        char t, d;
        cin >> t >> d;
        sp.push_back({t, d});
    }
    //左に落ちる奴の中で一番右にいるロボットを特定する
    int lb = -1, ub = N;
    while(ub - lb > 1){
        int mid = (ub + lb) / 2;
        //cout << " " << mid << " " << ub << " " << lb << endl;
        int ad = mid;

        bool flag = false;
        for(auto& u : sp){
            if(S[ad] != u.first) continue;
            if(u.second == 'L') ad--;
            else ad++;
            if(ad == -1){
                flag = true;
                break;
            }else if(ad == N){
                break;
            }
        }
        if(flag) lb = mid;
        else ub = mid;
    }
    ans -= lb + 1;

    //右に落ちる奴の中で一番左にいるロボットを特定する
    lb = -1, ub = N;
    while(ub - lb > 1){
        int mid = (ub + lb) / 2;
        int ad = mid;

        bool flag = false;
        for(auto& u : sp){
            if(S[ad] != u.first) continue;
            if(u.second == 'L') ad--;
            else ad++;
            if(ad == N){
                flag = true;
                break;
            }else if(ad == -1){
                break;
            }
        }
        if(flag) ub = mid;
        else lb = mid;
    }
    ans -= N - ub;
    cout << ans << endl;
    return 0;
}