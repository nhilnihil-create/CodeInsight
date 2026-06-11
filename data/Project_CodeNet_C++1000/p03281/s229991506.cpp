#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n; int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(i&1){
            int foo = 0;
            for(int j = 1; j <= i; j++){
                if(i%j == 0)foo++;
            }
            if(foo == 8){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
