#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin >> N;

    vector<string> B(N);
    vector<string> R(M);
    map<string,int> ans;

    for(int i=0; i<N; i++){
        string s; cin >> s;
        if(ans.count(s)){
            ans.at(s)++;
        }else{
            ans[s] = 1;
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        string t; cin >> t;
        if(ans.count(t)){
            ans.at(t)--;
        }else{
            ans[t] = -1;
        }
    }

    int m=0;
    for(auto cnt : ans){  
        auto v = cnt.second;
        m = max(m,v);
         // cout << k << " " << v << endl;
    }

    cout << m << endl;
}