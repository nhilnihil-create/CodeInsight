#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int N, Y;
    cin >> N >> Y;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i + j <= N){
                int k = N - (i + j);
                if(Y == i * 10000 + j * 5000 + k * 1000){
                    cout << i << ' ' << j << ' ' << k;
                    goto Exit;
                }
            }
        }
    }
    cout << "-1 -1 -1";
    Exit: ;

}