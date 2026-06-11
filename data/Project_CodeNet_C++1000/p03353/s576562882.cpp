#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    char c = 'z';
    string cd = "";
    set<string> v;
    rep(i, s.size())
    {
        cd = "";
        cd += s[i];
        v.insert(cd);
    }
    queue<string> u;
    int cnt = 1;
    while(cnt <= 5){
        for(auto e:v){
            if(e.size() >= cnt){
                u.push(e);
            }
        }
        while(!u.empty()){
            auto e = u.front();
            u.pop();
            rep(i,s.size()-e.size()){
                bool flag = true;
                rep(j,e.size()){
                    if(s[i+j] != e[j]){
                        flag = false;
                    }                                        
                }
                if(flag){
                    v.insert(e + s[i + e.size()]);
                }
            }
        }
        cnt++;
    }
    cnt = 1;
    for(auto e : v){
        if(cnt == k){
            cout << e << endl;
            return 0;
        }
        cnt++;
    }
}
