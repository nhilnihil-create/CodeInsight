#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int input;
    vector<int> k(M);
    vector<vector<int>> s(M);
    for(int i=0; i<M; i++){
        cin >> k.at(i);
        for(int j=0; j<k.at(i); j++){
            cin >> input;
            s.at(i).push_back(input);
        }
    }
    vector<int> p(M);
    for(int i=0; i<M; i++) cin >> p.at(i);
    
    int ans=0;
    
    for(int bit=0; bit<(1<<N); bit++){
        int cnt=0;
        for(int i=0; i<M; i++){
            int scnt=0;
            for(int j=0; j<k.at(i); j++){
                if(bit & (1<<s.at(i).at(j)-1)) scnt++;
            }
            if(scnt%2==p.at(i)) cnt++;
        }
        if(cnt==M) ans++;
    }
    cout << ans << endl;

}