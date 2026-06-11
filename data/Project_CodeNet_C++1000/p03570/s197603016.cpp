#include <bits/stdc++.h>
using namespace std;
string s;
unordered_map<int, int>cnt;
int main(){
    cin>>s;
    int cur = 0, x;
    for(int i = 0; i < s.size(); ++i){
        cur ^= (1 << (s[i] - 'a'));
        if(cur == 0){
            if(i == s.size() - 1){
                cout<<1<<endl;return 0;
            }
        }
        else{
            int x = 1e8;
            if(cnt[cur] > 0){
                x = min(x, cnt[cur]);
            }
            for(int j = 0; j < 26; ++j){
                if((cur ^ (1 << j)) == 0){ x = 1;break;}
                else{
                    if(cnt[cur ^ (1 << j)] > 0) x = min(x, cnt[cur ^ (1 << j)] + 1);
                    else{
                        x = min(x, cnt[cur ^ (1 << (s[i] - 'a'))] + 1);
                    }
                }
            }
            cnt[cur] = x;
        } 
    }
    cout<<cnt[cur]<<endl;
}