#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;
using LL = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; i++)
const int INF = numeric_limits<int>::infinity();

bool checker(LL num){
    bool three = false, five = false, seven = false;
    while (num > 0){
        switch(num % 10){
            case 3:
                three = true;
                break;
            case 5:
                five = true;
                break;
            case 7:
                seven = true;
                break;
        }
        num /= 10;
        if (three && five && seven){
            return true;
        }
    }

    return false;
}

int main(void)
{
    LL N;
    cin >> N;

    queue<LL> q;
    LL count = 0;
    q.push(3);
    q.push(5);
    q.push(7);
    while (true){
        int i = 0;
        rep (j, pow(3, i+1)){
            LL num = q.front();
            if (num > N){
                goto End;
            }
            q.pop();
            q.push(num*10 + 3);
            q.push(num*10 + 5);
            q.push(num*10 + 7);
            if (checker(num)){
                count++;
            }
        }
    }
End:;
    printf("%lld\n", count);
    return 0;
}