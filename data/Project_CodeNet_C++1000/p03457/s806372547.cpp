#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    int N;  cin >> N;
    int t, x, y, lx, ly, lt, tmp;
    lx = 0;
    ly = 0;
    lt = 0;
    for(int i=0; i<N; i++){
        cin >> t >> x >> y;
        tmp = abs(x-lx) + abs(y-ly);
        if(tmp > t-lt){
            cout << "No";
            return 0;
        }else if(tmp%2 != (t-lt)%2){
            cout << "No";
            return 0;
        }else{
            lx = x;
            ly = y;
            lt = t;
        }
    }
    cout << "Yes";
    return 0;
}