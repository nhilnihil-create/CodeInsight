//
//  CPlibrary
//
//  Created by Tanmay Singh on 3/03/2020.
// INDIAN INSTITUTE OF TECHNOLOGY (BHU) , VARANASI
//  Copyright Â© 2020 Tanmay Singh. All rights reserved.
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
 
typedef std::vector< int > vi;
typedef std::vector< long long int > vll;
typedef std::vector< vi > vvi;
typedef long long int bigint ;
using namespace std;
 

typedef long long ll;

int main(){
    int A , B , C , X ; cin >> A >> B >> C >> X ;
    long long int cnt = 0 ;
    for( int i = 0 ; i <= A ; i++ ){
        for( int j = 0 ; j <= B ; j++ ){
            for( int k = 0 ; k <= C ; k++ ){
                if( i * 500 + j * 100 + 50 * k == X )
                    cnt++ ;
            }
        }
    }
    cout << cnt << endl ;
    return 0 ;
}
