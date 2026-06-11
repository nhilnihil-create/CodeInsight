#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin>>S;
    deque<char> s;
    for(auto c : S){
        s.push_back(c);
    }
    int ans = 0;
    while(s.size() > 1){
        char l = s.front(), r = s.back();
        // cout<<l<<" "<<r<<endl;
        if(l==r) {
            s.pop_front(); s.pop_back();
            continue;
        }
        else if(l=='x' && r!='x'){
            s.push_back('x');
            ans++;
            // s.pop_front(); s.pop_back();
            continue;
        }
        else if(l!='x' && r=='x'){
            s.push_front('x');
            ans++;
            // s.pop_front(); s.pop_back();
            continue;
        }
        else if(l !='x' && r != 'x'){
            ans=-1;
            break;
        }
    }
    cout<<ans<<endl;
}
// code_festival_2017_qualc_c