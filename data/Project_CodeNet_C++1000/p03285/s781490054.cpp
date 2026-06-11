#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i = 0; i<= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(i*4+j*7 == n){
                cout << "Yes" << endl; return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
