//              *           ***********    *********         *         **           *
//            *   *         *         *       ***          *   *       *  *         *
//          *       *       *         *       ***         *     *      *    *       *
//         ***********      ***********       ***        *********     *      *     *
//        *           *     *  *              ***       *         *    *        *   *
//       *             *    *     *           ***      *           *   *          * *
//       *             *    *        **    *********   *           *   *           **

//       **********                *                ***********       ***********
//       *        *              *   *              *                 *
//       *      *              *       *            *                 *
//       * * *                ***********           ***********       ***********
//       * * *               *           *                    *                 *
//       *      *           *             *                   *                 *
//       *        *        *               *                  *                 *
//       **********        *               *        ***********       ***********

#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
#include <numeric>
#include <float.h>
#include <stdio.h>
#include <chrono>
#include <cmath>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

#define ll long long
#define dou double
#define Turbo std::ios::sync_with_stdio(false)

using namespace std ;

// Until 256 ;)

int main () {
    Turbo ;
    int n , a , b ;
    cin >> n >> a >> b ;
    cout << min (a , b) << ' ' ;
    if (a + b > n) {
        cout << (a + b) - n << '\n' ;
    }
    else {
        cout << 0 << '\n' ;
    }
    return 0 ;
}
