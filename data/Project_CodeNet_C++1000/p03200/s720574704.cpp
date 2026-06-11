#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    ll b_cnt = 0, ans = 0;
    //ある白石に対して，その左側にある黒石の数だけ入れ替えが発生する
    for(int i = 0; i < n; i++){
        if(s[i] == 'B') b_cnt++;
        else{
            ans += b_cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
