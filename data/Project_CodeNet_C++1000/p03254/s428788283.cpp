#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int x;
    cin >> x;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    sort(all(vec));
    int ans = 0;
    while(x > 0 && ans < N){
        if (x - vec[ans] < 0){
            x -= vec[ans];
        }
        else if (ans == N - 1){
            if (x == vec[ans]){
                ans++;
            }
            else{
                x = -1;
            }
        }
        else{
            x -= vec[ans];
            ans++;
        }
    }
    cout << ans << endl;
}

