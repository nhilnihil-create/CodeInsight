#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int a, b, k, ans = 0;
    cin >> a >> b >> k;
    for(int i = 200; i >= 1; i--){
        if(a % i == 0 && b % i == 0){
//            cout << "   " << i << endl;
            ans ++;
            if(ans == k)
                return cout << i, 0;
        }
    }
    return 0;
}