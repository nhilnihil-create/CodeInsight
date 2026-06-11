#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int main(void)
{
    /*
    ABC 103 D, 2018_07_21
    https://atcoder.jp/contests/abc103/tasks/abc103_d
    貪欲法, 区間スケジューリング
    */
    int N, a;
    cin >> N;

    int sum =0;
    for(int i=0; i<N; i++)
    {
        cin >> a;
        sum += a-1;
    }

    cout << sum << endl;



    return 0;
}
