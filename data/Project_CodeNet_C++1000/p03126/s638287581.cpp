#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(m+1, 0);

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int in;
            cin >> in;
            v[in]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < m+1; i++){
        if(v[i] >= n) ans++;
    }
    cout << ans << endl;
}