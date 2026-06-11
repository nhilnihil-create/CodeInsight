 #include <bits/stdc++.h>

using namespace std;

#define ll long long

int main (){
    int n ;
    cin >> n;
    int data [n] ;
    for (int i = 0 ; i < n ; i ++ ){
        cin >> data [i] ;
    }
    for (int i = 0 ; i < n ; i ++ )
        if (i < data[i]){
            cout << -1 ;
            return 0;
    }
    ll ans = 0;
    for (int i = 1 ; i < n ; i ++ ){
        if (data[i] != data[i-1] + 1){
            if (data[i] > data[i-1] + 1 ){
                cout << -1 ;
                return 0;
            }
            ans += data[i-1] ;
        }
    }
    ans += data [n-1];
    cout << ans ;
}
