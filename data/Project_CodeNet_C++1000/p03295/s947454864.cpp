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
    int N, N_Q;
    cin >> N >> N_Q;

    vector< pair<int, int> > end_start(N_Q);
    int j, k;
    for(int i=0; i<N_Q; i++)
    {
        cin >> j >> k;
        end_start[i] = make_pair(k, j);
    }

    sort(end_start.begin(), end_start.end() );

    int N_removed = 0;
    double pos = -1;
    for(int i=0; i<N_Q; i++)
    {
        if(end_start[i].second >= pos)
        {
            N_removed ++;
            pos = end_start[i].first-0.5;
        }
    }

    cout << N_removed << endl;



    return 0;
}
