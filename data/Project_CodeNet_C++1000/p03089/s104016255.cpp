#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> b(N);
    rep(i, N){
        cin >> b[i];
        b[i]--;
    }

    vector<int> a;
    rep(i, N){
        int pivot = -1;
        for (int j = b.size()-1; j >= 0; j--){
            if(b[j] == j){
                pivot = j;
                break;
            }
        }

        if(pivot == -1){
            cout << -1 << endl;
            return 0;
        }

        a.push_back(pivot+1);
        b.erase(b.begin()+pivot);
    }

    rep(i, N){
        cout << a[N-1-i] << endl;
    }

    return 0;
}