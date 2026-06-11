#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, m;
    cin >> n >> m;

    vector< vector< long long int > > rates;
    long long int i;

    for(i=0; i<n; i++){
        long long int rate, can;
        cin >> rate >> can ;
        vector<long long int> shop;
        shop.push_back(rate);
        shop.push_back(can);
        rates.push_back(shop);
    }

    sort(rates.begin(), rates.end());

    /*for(i=0; i<n; i++){
        cout << rates[i][0]<< " " << rates[i][1] << endl;
    }*/
    long long int bought =0, cost = 0;
    i = 0;
    while(bought < m){
        long long int dif = m - bought;
        if(rates[i][1] > dif){
            bought += dif;
            cost += dif*rates[i][0];
        } else {
            bought += rates[i][1];
            cost += rates[i][1]*rates[i][0];
            i++;
        }
    }
    cout << cost << endl;
}

