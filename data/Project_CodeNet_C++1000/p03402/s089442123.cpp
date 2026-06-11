#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

int A, B;
vector<string> grid(101);

int main(void){
    
    scanf("%d %d", &A, &B);
    for(int i = 1; i <= 50; ++i){ string s(101, '#'); grid[i] = s; }
    for(int i = 51; i <= 100; ++i){ string s(101, '.'); grid[i] = s; }
    
    int black = 1, white = 1;
    
    for(int i = 1; i <= 50; i += 2){
        for(int j = 1; j <= 100; ++j){
            if(white == A) continue;
            if(j % 2 != 0) grid[i][j] = '.', ++white;
        }
    }
    
    for(int i = 100; i >= 51; i -= 2){
        for(int j = 1; j <= 100; ++j){
            if(black == B) continue;
            if(j % 2 == 0) grid[i][j] = '#', ++black;
        }
    }
    
    printf("100 100\n");
    for(int i = 1; i <= 100; ++i){
        for(int j = 1; j <= 100; ++j){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}