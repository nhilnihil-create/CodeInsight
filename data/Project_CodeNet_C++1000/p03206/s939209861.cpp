#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007

using namespace std;
int main(){
    FAST
    int d; cin >> d;
    cout << "Christmas ";
    if(d==25){
        return 0;
    }
    if(d==24){
        cout << "Eve";
    }
    if(d==23)
    {
        cout << "Eve Eve";
    }
    if(d==22){
        cout << "Eve Eve Eve";
    }
    return 0;
}
