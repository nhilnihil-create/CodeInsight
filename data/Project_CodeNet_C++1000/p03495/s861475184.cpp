#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
int main()
{
    int K,N;
    cin >> N >> K;
    int temp;
    map<int,int>numbers;
    REP(i,N){
        cin >> temp;
        numbers[temp]++;
    }
    int count = 0;
    int nullity = numbers.size() -K;
    if(nullity <= 0){
        fin(0);return 0;
    }
    //printf("numbers.size = %d\n",numbers.size());
    //printf("nullty = %d\n",nullity);
    REPD(i,1,200000){
        for (const auto &p : numbers)
        {
            if(p.second == i){
                //printf("%dを書き換え\n",p.first);
                count += p.second;
                nullity--;
            }
            if(nullity == 0){
                fin(count);return 0;
            }
        }
    }
    fin("!!");
    return 0;
}