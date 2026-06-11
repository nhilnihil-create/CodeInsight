//
//  CPlibrary
//
//  Created by Tanmay Singh on 3/03/2020.
// INDIAN INSTITUTE OF TECHNOLOGY (BHU) , VARANASI
//  Copyright © 2020 Tanmay Singh. All rights reserved.
//#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
 
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <climits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
 
#define FAST(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define mod 1000000007
typedef long long int  bigint ;
typedef std::vector< int > vi;
typedef std::vector< long long int > vll;
typedef std::vector< vi > vvi;
 
using namespace std;

int main(){
    FAST() ;
    int A , B , C ; cin >> A >> B >> C ;
    int arr[] = { A , B , C } ;
    sort( arr , arr + 3 ) ;
    int cnt1 = 0 , cnt2 = 0 ;
    cnt1 += (arr[2] - arr[0]) / 2 ;
    cnt2 += ( arr[2] - arr[1] ) / 2 ;
    arr[0] = arr[0] + 2 * cnt1 ;
    arr[1] = arr[1] + 2 * cnt2 ;
    sort( arr , arr + 3 ) ;
    if( arr[0] == arr[1] && arr[1] == arr[2] ){
        cout << cnt1 + cnt2 << endl ;
        return 0 ;
    }
    if( arr[0] == arr[1] ){
        cout << cnt1 + cnt2 + arr[2] - arr[1] << endl ;
        return 0 ;
    }
    if( arr[0] != arr[1] ){
        cout << cnt1 + cnt2 + 2 << endl ;
    }
    return 0 ;
}
