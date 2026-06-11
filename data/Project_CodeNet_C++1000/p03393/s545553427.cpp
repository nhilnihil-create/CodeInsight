#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/


int main(){
    string s; cin >> s;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    int n = s.size();
    if(n != 26){
        set<char> count;
        rep(i, n){
            count.insert(s[i]);
        }
        char c = 'a';
        bool flag = false;
        for(auto it : count){
            if(it != c){
                s += c;
                cout << s << endl;
                flag = true;
                return 0;
            }
            c++;
        }
        if(!flag){
            s += c;
            cout << s << endl;
            return 0;
        }
    }

    if(n == 26){
        vector<char> vec;
        int m = s.size();
        for(int i = 0; i < m; i++){
            vec.push_back(s[i]);
        }
        string t = s;
        next_permutation(vec.begin(), vec.end());
        string ans = "";

        for(int i = 0; i < vec.size(); i++){
            ans += vec[i];
            if(vec[i] > t[i])break;
        }
        cout << ans << endl;
    }
}