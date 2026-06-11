#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
int main(void)
{
    int N, i, a[101], ans=0, count=0;

    cin >> N;

    for(i=1; i<=N; i++){
        cin >> a[i];
    }

    for(i=2; i<=N; i++){
        if(a[i] == a[i-1]){
            count++;

            if(i == 2){
                count++;
            }
        }

        else{
            ans += count/2;

            count = 1;
        }
    }

    ans += count/2;

    cout << ans << endl;
 
    return 0;
}