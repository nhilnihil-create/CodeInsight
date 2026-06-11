#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;

int main(void){

    vector<long long> lyu(87);
    lyu.at(0)=2;
    lyu.at(1)=1;
    for (int i = 2; i < 87; i++)
    {
        lyu.at(i)=lyu.at(i-1)+lyu.at(i-2);
    }
    
    long long n;
    cin >> n;
    cout << lyu.at(n) << endl;
}
