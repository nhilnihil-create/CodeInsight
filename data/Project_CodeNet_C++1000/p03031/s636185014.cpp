#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> k(M);
    vector<vector<int>> s(M);
    vector<int> p(M);

    for(int i=0; i<M; i++){
        cin >> k.at(i);
        for(int j=0;j<k.at(i); j++){
            int tmp;
            cin >> tmp;
            s.at(i).push_back(tmp);
        }
    }
    for(int i=0; i<M; i++){
        cin >> p.at(i);
    }

    int ans = 0;
    for(int st=0; st < pow(2,N); st++){ // switch status
        for(int i=0; i<M; i++){ // light
            int sum = 0;
            for(int j=0; j<k.at(i); j++){ 
                if(((1 << (s.at(i).at(j)-1)) & st) != 0) sum++; 
            }
            if((sum%2) != p.at(i)){
                break;
            }
            if(i == M-1) ans++;
        }
    }

    cout << ans << endl;
    return 0;

} 
