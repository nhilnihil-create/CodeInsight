#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(void)
{

    cin.tie(0);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    vector<long> vec;
    long long inp;
    rep(i, n)
    {
        cin >> inp;
        vec.push_back(inp - 1 - i);
    }

    sort(vec.begin(), vec.end()); // vector

    long size = vec.size();
    long toru;
    long mid;

    if (size % 2 == 1) {
        mid =  vec[(size - 1) / 2];
    } else {
        mid = (vec[(size / 2) - 1] + vec[size / 2]) / 2;
    }

    //cout << mid;


    long sum = 0;
    rep(i,n){
        vec[i] -= mid;
        if(vec[i]<0) vec[i] *= -1;
        sum += vec[i];
    }

    cout << sum;

    return 0;
}