#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<long long int, pair<long long int, long long int>>> dish(n);
    for(int i=0; i<n; i++){
        long long int a, b;
        cin >> a >> b;
        dish[i] = {a+b, {a,b}};
    }
    sort(dish.begin(),dish.end());
    reverse(dish.begin(),dish.end());

    long long int ans = 0;
    for(int i=0; i<n; i++){
        if(i % 2 == 0) ans += dish[i].second.first;
        if(i % 2 == 1) ans -= dish[i].second.second;
    }
    cout << ans << endl;
    return 0;
}