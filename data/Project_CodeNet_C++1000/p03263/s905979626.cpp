#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long h, w;
    cin >> h >> w;

    long long a[h][w];

    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    long long x = 0, y = 0;
    vector<long long> pre_x;
    vector<long long> pre_y;
    vector<long long> next_x;
    vector<long long> next_y;
    long long count = 0;

    while(count < h*w-1){
    
        if(y % 2 == 0){
            if(a[y][x] % 2 != 0){
                pre_x.push_back(x);
                pre_y.push_back(y);
                a[y][x]--;
                if(x + 1 < w){
                    //printf("a\n");
                    a[y][x + 1]++;
                    next_x.push_back(x + 1);
                    next_y.push_back(y);
                }
                else if(y + 1 < h){
                    //printf("b\n");
                    a[y + 1][x]++;
                    next_x.push_back(x);
                    next_y.push_back(y + 1);
                }
            }

            if(x + 1 < w){
                x++;
            }
            else if(y + 1 < h){
                y++;
            }
        }
        else{
            if(a[y][x] % 2 != 0){
                pre_x.push_back(x);
                pre_y.push_back(y);
                a[y][x]--;
                if(x - 1 >= 0){
                    //printf("c\n");
                    a[y][x - 1]++;
                    next_x.push_back(x - 1);
                    next_y.push_back(y);
                }
                else if(y + 1 < h){
                    //printf("c\n");
                    a[y + 1][x]++;
                    next_x.push_back(x);
                    next_y.push_back(y + 1);
                }
            }
            if(x - 1 >= 0){
                x--;
            }
            else if(y + 1 < h){
                y++;
            }
        }
        count++;
    }

    cout << pre_x.size() << endl;

    for(long long i = 0; i < pre_x.size(); i++){
        printf("%lld %lld %lld %lld\n", pre_y[i]+1, pre_x[i]+1, next_y[i]+1, next_x[i]+1);
    }
    return 0;
}