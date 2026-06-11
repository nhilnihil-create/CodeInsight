#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    vector<pair<int,int>> dish(5);
    rep(i, 5){
        int tmp, mod;
        cin >> tmp;
        mod = tmp%10;
        if(mod != 0) dish[i].first = mod;
        else dish[i].first = 10;
        dish[i].second = tmp;
    }

    sort(dish.begin(), dish.end());

    int sum = 0;
    rep(i, 5){
        sum += 10 -dish[i].first;
        sum += dish[i].second;
    }
    sum -= 10 - dish[0].first;
    
    cout << sum << endl;

    return 0;
}