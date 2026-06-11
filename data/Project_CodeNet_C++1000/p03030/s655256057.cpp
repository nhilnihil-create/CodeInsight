#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <map>
#include <utility>

using namespace std;


int main(){
    int n ;
    cin >> n;

    pair<pair<string, int>, int > p[n];

    string g;
    int h;

    for(int i = 0 ; i< n; i++){
        cin >> g;
        cin >> h;
        p[i] = make_pair(make_pair(g, 100 - h),i);
    }

    sort(p, p+n);

    for(int i = 0; i < n; i++){
        int d = p[i].second;
        cout << d+1 << endl;
    }



    
}