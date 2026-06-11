#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    double n, a, sum = 0, yen;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        cin >> s;
        if(s == "BTC"){
            yen = a *  380000;
            sum = sum + yen;
        }
        else{
            sum = sum + a;
        }
    }
    cout << sum;


}





///promy_pompom
//hello world
