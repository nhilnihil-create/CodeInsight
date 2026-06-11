#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int cs[26];
string NG = "zyxwvutsrqponmlkjihgfedcba";

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;cin>>s;
    if(s==NG){
        cout<<-1<<endl;
        return 0;
    }
    int n = s.size();
    if(n!=26){
        for(auto a : s){
            cs[(int)(a-'a')] = 1;
        }
        rep(i, 26){
            if(cs[i] == 0){
                cout<<s<<(char)(i+'a')<<endl;
                return 0;
            }
        }
    }else{
        string t = s;
        next_permutation(all(t));
        for(int i=0; i<26; i++){
            if(s[i]==t[i]){
                cout<<s[i];
            }else{
                cout<<t[i]<<endl;
                return 0;
            }
        }
    }
}