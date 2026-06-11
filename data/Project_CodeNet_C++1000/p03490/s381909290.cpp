#include <iostream>
#include <vector>
using namespace std;
char nnnnn[8010];
int xcor, ycor;
vector <int> x;
vector <int> y;
int total_sum_X =0;
int total_sum_Y =0;
bool sub1[8010][8010]; ///1st -->sum 2nd --> elements
bool sub2[8010][8010];
bool check_subs2(int sumi)
{
    for (int i = 0; i <=y.size(); i++)
        sub2[i][0]= true;
    for (int i = 1 ; i<=sumi; i++)
        sub2 [0][i] = false;
    for (int i = 1 ; i<=y.size(); i++)
    {
        for (int j = 1; j<=sumi; j++)
        {
            if (j<y[i-1])
            {
                sub2[i][j] = sub2[i-1][j];
            }
            else
            {
                sub2[i][j] = sub2[i-1][j] || sub2[i-1][j-y[i-1]];
            }
        }
    }
    return sub2[y.size()][sumi];
}
bool check_subs1(int sumi)
{
    for (int i = 0; i <=x.size(); i++)
        sub1[i][0]= true;
    for (int i = 1 ; i<=sumi; i++)
        sub1 [0][i] = false;
    for (int i = 2 ; i<=x.size(); i++)
    {
        for (int j = 1; j<=sumi; j++)
        {
            if (j<x[i-1])
            {
                sub1[i][j] = sub1[i-1][j];
            }
            else
            {
                sub1[i][j] = sub1[i-1][j] || sub1[i-1][j-x[i-1]];
            }
        }
    }
    return sub1[x.size()][sumi];
}
int main()
{
    cin >> nnnnn;
    bool flip =false;
    cin >> xcor >> ycor;
    int sum =0;
    for (int i = 0; nnnnn[i]!=0; i++)
    {

        if (flip ==false)
        {
            if (nnnnn[i]=='T')
            {
                flip = true;
                x.push_back(sum);
                total_sum_X = total_sum_X + sum;
                sum=0;
            }
            else
            {
                sum++;
            }
        }
        else
        {
            if (nnnnn[i]=='T')
            {
                flip = false;
                total_sum_Y = total_sum_Y + sum;
                y.push_back(sum);
                sum = 0;
            }
            else
            {
                sum++;
            }
        }

    }
    if (flip == false)
    {
        total_sum_X = total_sum_X + sum;
        x.push_back(sum);
    }
    else
    {
        y.push_back(sum);
         total_sum_Y = total_sum_Y + sum;
    }
    if ((total_sum_X + xcor)%2 == 1 || (total_sum_Y + ycor)%2==1)
    {
        cout << "No";
        return 0;
    }

    if (check_subs1((total_sum_X+xcor)/2 - x[0])==true && check_subs2((total_sum_Y+ycor)/2)==true)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}

