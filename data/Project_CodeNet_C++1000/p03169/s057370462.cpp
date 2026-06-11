#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

double recurse(int N, int ones, int twos, int threes);
static double dp[301][301][301];

int main()
{
    /*
    for (int i = 0; i < 903; i++) {
        for (int j = 0; j < 903; j++) {
            for (int k = 0; k < 903; k++) {
                dp[i][j][k] = -1.0;
            }
        }
    }

    printf("Done filling array\n");
    */
    int N;

    cin >> N;

    int ones = 0;
    int twos = 0;
    int threes = 0;

    for (int i = 0; i < N; i++)
    {
        int tmp;

        cin >> tmp;

        if (tmp == 1)
        {
            ones++;
        }
        else if (tmp == 2)
        {
            twos++;
        }
        else
        {
            threes++;
        }
    }

    cout << setprecision(15);
    cout << ones + twos * 2 + threes * 3 + recurse(N, ones, twos, threes) << endl;
}

double recurse(int N, int ones, int twos, int threes)
{
    //Base case:
    if (ones == 0 && twos == 0 && threes == 0)
    {
        return 0.0;
    }

    if (dp[ones][twos][threes] != 0.0)
    {
        //printf("Used value here!\n");
        return dp[ones][twos][threes];
    }
    //Find probability of wasting a move
    int nonEmptyPlates = ones + twos + threes;
    double p_wasted = 1.0 - (double)nonEmptyPlates / N;

    double p1 = 0.0;
    double p2 = 0.0;
    double p3 = 0.0;

    //printf("State: ones = %d, twos = %d, threes = %d, p_wasted = %f\n", ones, twos, threes, p_wasted);

    if (ones > 0)
    {
        p1 = (double)ones / nonEmptyPlates * recurse(N, ones - 1, twos, threes);
    }

    if (twos > 0)
    {
        p2 = (double)twos / nonEmptyPlates * recurse(N, ones + 1, twos - 1, threes);
    }

    if (threes > 0)
    {
        p3 = (double)threes / nonEmptyPlates * recurse(N, ones, twos + 1, threes - 1);
    }

    dp[ones][twos][threes] = p1 + p2 + p3 + p_wasted / (1 - p_wasted);
    return dp[ones][twos][threes];
    //return p1 + p2 + p3 + p_wasted / ((1 - p_wasted) * (1 - p_wasted)) * prob;
}