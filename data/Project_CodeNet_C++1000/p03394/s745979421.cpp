#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    if(n == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }else if(n == 4){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
        return 0;
    }else if(n == 6){
        cout << 2 << " " << 3 << " " << 4 << endl;
        cout << 8 << " " << 9 << " " << 10 << endl;
        return 0;
    }
    for(i = 0;8*(i+1) <= n;++i){
        rep(j,2){
            cout << 12*i + 6*j + 2 << endl;
            cout << 12*i + 6*j + 3 << endl;
            cout << 12*i + 6*j + 4 << endl;
            cout << 12*i + 6*j + 6 << endl;
        }
    }
    ll spare = n - 8*i;
    if(spare == 1){
        cout << 12*i + 6 << endl;
    }else if(spare == 2){
        cout << 12*i + 2 << endl;
        cout << 12*i + 4 << endl;
    }else if(spare == 3){
        cout << 12*i + 2 << endl;
        cout << 12*i + 4 << endl;
        cout << 12*i + 6 << endl;
    }else if(spare == 4){
        cout << 12*i + 2 << endl;
        cout << 12*i + 3 << endl;
        cout << 12*i + 4 << endl;
        cout << 12*i + 9 << endl;
    }else if(spare == 5){
        cout << 12*i + 2 << endl;
        cout << 12*i + 3 << endl;
        cout << 12*i + 4 << endl;
        cout << 12*i + 6 << endl;
        cout << 12*i + 9 << endl;
    }else if(spare == 6){
        cout << 12*i + 2 << endl;
        cout << 12*i + 3 << endl;
        cout << 12*i + 4 << endl;
        cout << 12*i + 6 << endl;
        cout << 12*i + 9 << endl;
        cout << 12*i + 12 << endl;
    }else if(spare == 7){
        cout << 12*i + 2 << endl;
        cout << 12*i + 3 << endl;
        cout << 12*i + 4 << endl;
        cout << 12*i + 6 << endl;
        cout << 12*i + 8 << endl;
        cout << 12*i + 9 << endl;
        cout << 12*i + 10 << endl;
    }

    return 0;
}