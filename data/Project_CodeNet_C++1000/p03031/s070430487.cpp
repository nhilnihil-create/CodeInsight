#include <bits/stdc++.h>
using namespace std;

const long long MOD = 2;


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for(int i = 0; i < M; ++i){
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j){
            int s;
            cin >> s;
            s--;
            a[s] |= 1 << i;
        }
    }
    int p = 0;
    for(int i = 0; i < M; ++i){
        int x;
        cin >> x;
        p |= x << i;
    }
    int ans = 0;
    for(int s = 0; s < (1 << N); s++){
        int t = 0;
        for(int i = 0; i < N; i++){
            if(s >> i & 1){
                t ^= a[i];
            }
        }
        if(t == p) ans++;
    }
    cout << ans << endl;
    /*
    int N, M;
    cin >> N >> M;
    vector<vector<int> > S;
    for(int i = 0; i < M; ++i){
        int k;
        cin >> k;
        vector<int> s;
        for(int j = 0; j < k; ++j){
            int ss;
            cin >> ss;
            s.push_back(ss);
        }
        S.push_back(s);
    }
    vector<int> p;
    for(int i = 0; i < M; ++i){
        int pp;
        cin >> pp;
        p.push_back(pp);
    }
    */
    /*
    for(auto i : p) cout << i << " ";
    cout << endl;
    for(auto i : S){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    */
    
    
    return 0;
}
