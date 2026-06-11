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
    string target = "keyence";
    int n = s.size();

    if(target == s){
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j <= n; j++){
            string ss = "";
            for(int k = 0; k < n; k++){
                if(i <= k && k <= j) continue;
                else ss.push_back(s[k]);
            }
            if(target == ss){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
