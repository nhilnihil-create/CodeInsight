/*
    g++ -std=c++14 -O2 -Wall a.cpp -o a && a
    g++ -std=c++14 -O2 -Wall a.cpp -o a && a < in.txt > out.txt
    */

//  io
#include <iostream>
//#include <fstream> //http://www.cplusplus.com/reference/fstream/fstream/
//#include <cstdio>
//#include <iomanip> //http://www.cplusplus.com/reference/iomanip/
//  util
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
//#include <functional> //http://www.cplusplus.com/reference/functional/
//#include <cstdlib>
//#include <cmath>
//#include <complex>
//#include <random>
//#include <bitset>
//  containers https://en.cppreference.com/w/cpp/container
#include <queue>
#include <vector>
//#include <set>
#include <tuple>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//  time
//#include <ctime>
//#include <chrono>
//                  https://en.cppreference.com/w/cpp/header/chrono
//                  http://www.cplusplus.com/reference/chrono/

using namespace std;
typedef vector<int> arri;
typedef vector<float> arrf;
typedef pair<int, int> pairi;
typedef long long ll;
typedef long double ld;
constexpr int mod = 1e9 + 7;
const ll inf = 0x7fffffffffffffff;
const ll infneg = -0x7fffffffffffffff;

//int modadd(int a, int b) { return ((a += b) < mod) ? a : (a - mod); }
//int modmult(int a, int b) { return (int)((a * b) % mod); }

//file input routed to stdinout
/*
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");
    std::cin.rdbuf(inFile.rdbuf());
    std::cout.rdbuf(outFile.rdbuf());
*/

long long dp[11][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u;
            cin >> u;
            if(u == -1) continue;

            sum += dp[u][1] ;
        }
    }

    cout << sum;
}