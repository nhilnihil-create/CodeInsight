#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll =  long long;
using P = pair<int,int>;
const int INF = 1001001001;
const int mod = 1000000007;


int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int sum = 0;
    double avg = 0;
    rep(i, N){
        sum += a[i];
    }
    avg = 1.0 * sum / N;

    int index = -1;
    double mini = INF;
    rep(i, N){
        if(mini > abs(a[i] - avg)){
            mini = abs(a[i] - avg);
            index = i;
        }
    }
    cout << index << endl;

}
