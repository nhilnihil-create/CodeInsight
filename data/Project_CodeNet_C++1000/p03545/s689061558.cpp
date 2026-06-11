#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    for(int bit=0;bit<(1<<3);++bit){
        int res=s[0]-'0';
        for(int i=0;i<3;++i){
            int t=s[i+1] - '0';
            if(bit&(1<<i)){
                res+=t;
            }else{
                res-=t;
            }
        }
        if(res==7){
            cout << s[0];
            for(int i=0;i<3;++i){
                if(bit&(1<<i)){
                    cout << "+";
                }else{
                    cout << "-";
                }
                cout << s[i+1];
            }
            cout << "=7" << "\n";
            return 0;
        }
    }
}   