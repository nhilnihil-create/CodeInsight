#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long c[10][10];

void warshall_floyd(){
    for(long long k = 0; k < 10; k++){
        for(long i = 0; i < 10; i++){
            for(long long j = 0; j < 10; j++){
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }
}

int main(){
    long long h, w;
    cin >> h >> w;

    for(long long y = 0; y < 10; y++){
        for(long long x = 0; x < 10; x ++){
            cin >> c[y][x];
        }
    }

    long long a[h][w];
    for(long long y = 0; y < h; y++){
        for(long long x = 0; x < w; x++){
            cin >> a[y][x];
        }
    }

    warshall_floyd();

    long long count = 0;
    for(long long y = 0; y < h; y++){
        for(long long x = 0; x < w; x++){
            if(a[y][x] != -1){
                count += c[a[y][x]][1];
                
            }
        }
    }

    cout << count << endl;
    return 0;

}