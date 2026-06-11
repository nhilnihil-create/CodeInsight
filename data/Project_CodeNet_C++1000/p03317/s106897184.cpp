#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    ll n, k, sum, c = 1;
    cin >> n >> k;
    ll arr[n];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(n == k){
        cout << 1;
    }
    else if(k == 2){
        cout << n - 1;
    }
    else{
        n = n - k - 1;;
        while(n >= 0){
            n = n - (k - 1);
            c++;
        }
        cout << c;
    }
}





///promy_pompom
//hello world
