#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <limits.h>
#include <float.h>
#include <numeric>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define fs first
#define sc second


int main(){
    int N, A, B;
    cin >> N >> A >> B;

    int x = (N + A - 1)/ A;
    if(x > B){
        cout << -1 << endl;
        return 0;
    }
    if(A + B > N+1){
        cout << -1 << endl;
        return 0;
    }

    vector<int> res;
    for(int i = 0; i <= N; i++){
        int z = ((N - i) + (A - 1)) / A;
        if(B == z + i){
            int start = N - A + 1;
            for(int j = 0; j < z; j++){
                for(int k = 0; k < A; k++){
                    if(start + k > i){
                        res.push_back(start + k);
                    }
                }
                start -= A;
            }
            for(int j = i; j > 0; j--){
                res.push_back(j);
            }
            break;
        }
    }

    for(auto r: res){
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
