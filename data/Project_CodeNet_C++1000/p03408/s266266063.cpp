#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int enum_divisors(int N)
{
    vector<int> res;
    for (int i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    return res.size();
}

int main(){
    int n,m;
    cin >> n;
    map<string,int> s;
    rep(i,n){
        string x;   cin >> x;
        s[x]++;
    }    
    cin >> m;
    map<string,int> t;
    rep(i,m){
        string x;   cin >> x;
        t[x]++;
    }

    int ans(0);
    for(auto a : s){
        if(t.count(a.first)==1){
            ans = max(ans,a.second-t[a.first]);
        }else{
            ans = max(a.second,ans);
        }
    }

    cout << ans << endl;

    return 0;
}