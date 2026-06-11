#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    list<int> b;
    for (int i = 0; i < N; i++){
        int x; cin >> x;
        b.push_back(x);
    }
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        int k = N - i;
        auto lastpos = b.end();
        int pos = 1;
        for (auto iter = b.begin(); iter != b.end(); ++iter)
        {
            //cout << pos << " " << *iter << endl;
            if(*iter == pos) lastpos = iter;
            pos++;
        }

        if(lastpos==b.end()){
            cout << -1 << endl;
            return 0;
        }
        //cout << *lastpos << endl;
        ans.push_back(*lastpos);
        b.erase(lastpos);
    }
    reverse(ans.begin(), ans.end());
    for(int i: ans) cout << i << '\n';    
}