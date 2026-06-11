#include<bits/stdc++.h>
using namespace std;

int main(){

    string s; cin >> s;
    int n = (int)s.size();

    int ok = 1;
    int ng = n + 1;
    while(ng - ok > 1){
        int d = (ok + ng) / 2;
        
        vector<int> vec(n, false);
        for(int i = d; i < n; i++){
            vec[i] = vec[n - i - 1] = true;
        }

        set<char> S;
        for(int i = 0; i < n; i++) if(!vec[i]) S.insert(s[i]);

        if(S.size() <= 1) ok = d;
        else ng = d;
    }

    cout << ok << endl;
    return 0;
}