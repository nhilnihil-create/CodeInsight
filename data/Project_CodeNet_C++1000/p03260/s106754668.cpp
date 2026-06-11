#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    for(int i = 1; i <= 3; i++){
        if((a*b*i)&1){
            cout << "Yes" << endl; return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
