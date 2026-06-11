#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N,cnt= 0;
    cin >> N;
    vector<ll> ans;
    queue<ll> que;

    que.push(3);
    que.push(5);
    que.push(7);
    char p[3] ={'3','5','7'};
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(int i = 0; i < 3; i++){
            string tmp = to_string(v);
            tmp += p[i];
            if(stoll(tmp) <= N){
                que.push(stoll(tmp));
                ans.push_back(stoll(tmp));
            }
        }
    }

    for(int i = 0; i < ans.size(); i++){
        bool flag_3 = false;
        bool flag_5 = false;
        bool flag_7 = false;
        for(int j = 0; j < to_string(ans[i]).size(); j++){
            if(to_string(ans[i])[j] == '3') flag_3 = true;
            if(to_string(ans[i])[j] == '5') flag_5 = true;
            if(to_string(ans[i])[j] == '7') flag_7 = true;
        }
        if(flag_7 && flag_5 && flag_3){
            cnt++;
        }
    }
    
    cout << cnt << endl;
}



