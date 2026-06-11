#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

std::string to_binString(int val)
{
    if( !val )
        return std::string("0");
    std::string str;
    while( val != 0 ) {
        if( (val & 1) == 0 )  // val は偶数か？
            str.insert(str.begin(), '0');  //  偶数の場合
        else
            str.insert(str.begin(), '1');  //  奇数の場合
        val >>= 1;
    }
    return str;
}


int main(void)
{
    /*
    動的計画法に、セグメント木(Minimum Spanning Tree)を用いることで高速化を図る
    */
    int Score_Goal, tmp_i, tmp_i2;
    cin >>tmp_i >> Score_Goal;
    const int N_Problems = tmp_i; // max = 10

    pair<int, int> N_Bonus[N_Problems]; // [問題数, ボーナス]

    for(int i=0; i<N_Problems; i++)
    {
        cin >> tmp_i >> tmp_i2;
        N_Bonus[i] = make_pair(tmp_i, tmp_i2);
    }

    int N_itemsMin = 0;
    int StatesMax = 1<< N_Problems;

    int Score_withBonus[N_Problems];
    for(int i=0; i<N_Problems; i++)
    {
        Score_withBonus[i] = (i+1) * 100* N_Bonus[i].first + N_Bonus[i].second;
        N_itemsMin += N_Bonus[i].first; //到達可能な個数の最小値
    }
    // cout << StatesMax << endl;


    for(int State = StatesMax-1; State>=0; State--)
    {
        int Score =0, N_items=0; //最上位: 1つ目
        for(int j=0; j<N_Problems; j++)
        {
            if(State >>(N_Problems-1-j) & 1)
            {
                Score += Score_withBonus[j];
                N_items += N_Bonus[j].first;
            }
        }

        if(Score >= Score_Goal)
        {
            // cout << "G  " << to_binString(State) << "  " << N_items << endl;
            N_itemsMin = min(N_itemsMin, N_items);
        }
        else if(State < StatesMax-1)
        {
            int State_back = ~State;
            int Last = State_back & (-State_back);
            int pos = (int) ( N_Problems-1-log(1.0*Last)/log(2.0) );
            int count = ceil( 1.0*(Score_Goal-Score) / 100/(pos+1) );
            if(count < N_Bonus[pos].first)
            {
                N_items += count;
                N_itemsMin = min(N_itemsMin, N_items);
                // cout << "WW  " << State << "  " << to_binString(Last) << ", " << count << "::: " << N_items << endl;
            }
        }
    }
    cout << N_itemsMin << endl;

    return 0;
}
