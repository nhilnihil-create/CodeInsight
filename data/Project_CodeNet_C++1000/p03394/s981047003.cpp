#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>
#include <complex>

const long INF = (1l << 30);
const long LINF = (1l << 60);

long n;
long d[2][8] = {
    {2, 10, 3, 9, 4, 8, 6, 12},
    {6, 2, 10, 3, 9, 4, 8, 12}
};

int main(){
    scanf("%ld", &n);
    if(n == 3){
        printf("2 5 63\n");
        return 0;
    }
    for(int i = 0; i < n; i++){
        printf("%ld ", d[n%2][i%8] + i / 8 * 12);
    }
    printf("\n");
}
