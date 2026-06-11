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

long n, q;
std::string s;
char spell[200005][2];

long drop(long a){
    for(int i = 0; i < q; i++){
        if(s[a] == spell[i][0]){
            if(spell[i][1] == 'L'){
                if(a == 0){
                    return 1l;
                }else{
                    a--;
                }
            }else{
                if(a == n-1){
                    return 2l;
                }else{
                    a++;
                }
            }
        }
    }
    return 0l;
}

long binary(long flag){
    long ok, ng;
    if(flag == 1){
        ok = -1, ng = n;
    }else{
        ok = n, ng = -1;
    }
    while(std::abs(ok-ng) > 1){
        long mid = (ok+ng)/2;
        if(drop(mid) == flag){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main(){
    scanf("%ld%ld", &n, &q);
    std::cin >> s;
    //*
    scanf("%*c");
    for(int i = 0; i < q; i++){
        scanf("%c%*c%c%*c", &spell[i][0], &spell[i][1]);
    }
    //*/
    /*
    for(int i = 0; i < q; i++){
        printf("  %hhd %hhd\n", spell[i][0], spell[i][1]);
    }
    printf("%hhd\n", '\n');
    printf("%hhd\n", ' ');
    //*/

    /*
    printf("  %ld\n", binary(1));
    printf("  %ld\n", binary(2));
    //*/
    printf("%ld\n", binary(2)-binary(1)-1);
}
