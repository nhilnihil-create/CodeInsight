#include <iostream>
#include <cstdio>
using namespace std;


long long d[10][10];

void warshall_floyd(long long n){
    for(long long k = 0;k < n;k++){ /*経由する頂点*/
        for(long long i = 0;i < n;i++){ /*始点*/
            for(long long j = 0;j < n;j++){ /*終点*/
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]); /*距離*/
            }
        }
    }
}

int main(){
    long long h, w;
    cin >> h >> w;

    for(long long i = 0; i < 10; i++){
        for(long long j = 0; j < 10; j++){
            cin >> d[i][j];
        }
    }

    warshall_floyd(10);

    long long cost = 0;
    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            long long a;
            cin >> a;
            if(a != -1) cost += d[a][1];
        }
    }

    cout << cost << endl;
    return 0;
}