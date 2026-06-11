#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

int main() {
        string s;
        int k;
        cin >> s >> k;
        int n = s.size();
        set<string> sub_str;
        rep(i,26){
                char alpha = 'a' + i;
                rep(j,n){
                        if(s[j] == alpha){
                                string now = "";
                                now += alpha;
                                int cnt = 1;
                                sub_str.insert(now);
                                while(cnt < k && j+cnt < n){
                                        now += s[j+cnt];
                                        sub_str.insert(now);
                                        cnt ++;
                                }
                        }
                }
                if(sub_str.size() >= k) break;
        }

        int i = 1;
        for(string p:sub_str){
                if(i == k) {
                        cout << p << endl;
                        break;
                }
                i++;
        }
        return 0;  
}