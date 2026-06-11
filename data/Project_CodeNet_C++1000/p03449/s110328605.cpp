#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,candy_max,get_candy,i,j;
    candy_max = 0;
    get_candy = 0;

    cin >> n;
    vector<vector<int>>  a(3,vector<int>(n+1));

    for(i=1; i<=n; i++){
        cin >> a.at(1).at(i);
    }
    for(i=1; i<=n; i++){
        cin >> a.at(2).at(i);
    }


//case1
    for(i=1; i<=n; i++){
        get_candy += a.at(1).at(i);
    }
    get_candy += a.at(2).at(n);
    candy_max = get_candy;
    get_candy = 0;


//case2
/*
    for(i=1; i<=n-1; i++){
        get_candy += a.at(1).at(i);
    }
    for(i=n-1; i<=n; i++){
        get_candy += a.at(2).at(i);
    }
    candy_max = max(candy_max, get_candy);
    get_candy = 0;
*/

//casex

    for(j=n-1; j>=1; j--){
        for(i=1; i<=j; i++){
        get_candy += a.at(1).at(i);
        }
        for(i=j; i<=n; i++){
            get_candy += a.at(2).at(i);
        }
        candy_max = max(candy_max, get_candy);
        get_candy = 0;
    }


    cout << candy_max << endl;

    return 0;
}