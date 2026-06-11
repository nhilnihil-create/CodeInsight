#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];
#define int long long

signed main(){
    int N; cin >> N;
    if(N==1){
        cout << "Hello World" << endl;
    }else{
        int a,b; cin >> a >> b;
        cout << a+b << endl;
    }
}