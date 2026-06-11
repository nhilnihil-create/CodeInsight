#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <regex>
typedef long long ll;
using namespace std;

void saiki(ll S, ll &count, int use, ll N) {
    if (S > N) return;
    if (use == 0b111) count++;

    saiki(S * 10 + 3, count, use | 0b001, N);
    saiki(S * 10 + 5, count, use | 0b010, N);
    saiki(S * 10 + 7, count, use | 0b100, N);
}
int main(void){
    ll N; cin >> N;
    ll count = 0;
    saiki(0,count,0,N);
    cout << count << endl;
}
