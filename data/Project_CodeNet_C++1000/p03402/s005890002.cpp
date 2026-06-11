#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;



int main(){
    int a, b; cin >> a >> b;
    vector<string> ans;
    int white = 0;
    int black = 0;
    rep(i,50){
        string s = "";
        if(i%2==0){
            rep(j,100){
                if(j%2==0){
                    if(a-1>white){
                        s += '.';
                        white++;
                    }else s += '#';
                }else s += '#';
            }
            ans.push_back(s);
        }else{
            rep(j,100) s += "#";
            ans.push_back(s);
        }
    }
    rep(i,50){
        string s = "";
        if(i%2==1){
            rep(j,100){
                if(j%2==0){
                    if(b-1>black){
                        s += '#';
                        black++;
                    }else s += '.';
                }else s += '.';
            }
            ans.push_back(s);
        }else{
            rep(j,100) s += ".";
            ans.push_back(s);
        }
    }
    cout << 100 << " " << 100 << endl;
    for(auto s : ans) cout << s << endl;
    //cout << ans.size() << endl;
}