#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main()
{
    int N, Y;   cin >> N >> Y;
    int c, tmp;
    Y /= 1000;
    N -= Y%5;
    c = Y%5;
    Y -= Y%5;
    if(Y%10 == 0){
        for(int i=0; i<=N; i++){
            for(int j=0; j<=N-i; j++){
                if(10*i + 5*j + N-i-j == Y){
                    cout << i << " " << j << " " << N-i-j+c << endl;
                    return 0;
                }
            }
        }
    }else{
        Y -= 5;
        tmp = N-1;
        for(int i=0; i<=tmp; i++){
            for(int j=0; j<=tmp-i; j++){
                if(10*i + 5*j + tmp-i-j == Y){
                    cout << i << " " << j+1 << " " << tmp-i-j+c << endl;
                    return 0;
                }
            }
        }
        tmp = N-5;
        for(int i=0; i<=tmp; i++){
            for(int j=0; j<=tmp-i; j++){
                if(10*i + 5*j + tmp-i-j == Y){
                    cout << i << " " << j << " " << tmp-i-j+c+5 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}