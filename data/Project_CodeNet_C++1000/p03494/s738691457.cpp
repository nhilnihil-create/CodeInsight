#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+5;

typedef long long ll;

int n;
int ar[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int ans = 0;
    while(true){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += (ar[i] % 2 == 0);
        }
        if(cnt == n){
            ans++;
            for(int i = 1; i <= n; i++){
                ar[i] >>= 1;
            }
        } else {
            break;
        }
    }
    cout << ans << "\n";
}
