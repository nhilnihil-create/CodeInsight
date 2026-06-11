#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

bool black[100][100];
int H = 100;
int W = 100;

int main(){
    int A,B;
    cin >> A >> B;
    cout << H << " " << W << endl;
    for(int h = 50; h < 100; h++){
        for(int w = 0; w < 100; w++){
            black[h][w] = true;
        }
    }

    int b = 0;
    while(B > 1){
        black[2*(b/100)][b%100] = true;
        b += 2;
        B--;
    }

    int a = 0;
    while(A > 1){
        black[51 + 2*(a/100)][a%100] = false;
        a += 2;
        A--;
    }

    for(int h = 0; h < 100; h++){
        for(int w = 0; w < 100; w++){
            if(black[h][w]) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}
