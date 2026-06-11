#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>

using namespace std;

typedef struct {
    int total;
    int a;
    int b;
}dish_t;

bool cmp(const dish_t& p, const dish_t& q) {
    return p.total > q.total;
}

int main() {
    long long N;
    cin >> N ;
    vector<dish_t> dish(N);
    for (int i = 0; i < N; i++) {
        cin >> dish[i].a >> dish[i].b;
        dish[i].total = dish[i].a + dish[i].b;
    }
    
    sort(dish.begin(),dish.end(), cmp);
    long long ans = 0;
    //cout << "after sort" << endl;
    //for (int i = 0; i < N; i++) 
        //cout << dish[i].a <<"  "<< dish[i].b << endl;;

    for (int i = 0; i < N; i++) {
        if (!(i % 2))
            ans += dish[i].a;
        else
            ans -= dish[i].b;
    }
    cout << ans << endl;
}
