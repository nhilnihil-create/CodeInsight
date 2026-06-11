#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;

int main()
{
    int people, day, choco;
    cin >> people >> day >> choco;
    vector<int> a(people);
    rep(i, people)
    {
        cin >> a[i];
        int eat_day = a[i] + 1;
        for (int j = 0; a[i] * j < day; j++)
        {
            choco++;
        }
    }

    cout << choco << endl;
    
    return 0;
}