#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int N;
    cin >> N;
    int t[N + 1] ={0}, x[N + 1] = {0}, y[N + 1] = {0};
    for(int i = 1; i <= N; i++){
        cin >> t[i] >> x[i] >> y[i];
    }


    for(int i = 1; i <= N; i++){
        int dt = t[i] - t[i-1];
        int dist = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        if(dist > dt){
            cout << "No" << endl;
            return 0;
        }

        if((dt % 2 == 0) && (dist % 2 == 1)){
            cout << "No" << endl;
            return 0;
        }

        if((dt % 2 == 1) && (dist % 2 == 0)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}