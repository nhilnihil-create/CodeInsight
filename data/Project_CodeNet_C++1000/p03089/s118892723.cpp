#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> b(N);
    for(int i=0; i<N; i++){
        cin >> b[i];
    }

    vector<int> ans;
    while(b.size() > 0){
        int n = b.size();
        bool ok = false;
        for(int i=n-1; i>=0; i--){
            if(b[i] == i+1){
                ans.push_back(i+1);
                b.erase(b.begin() + i);
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i=N-1; i>=0; i--){
        cout << ans[i] << endl;
    }
}
