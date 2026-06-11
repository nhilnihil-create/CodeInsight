#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<int>X1;
    vector<int>X2;
    rep(i, 0, N){
        int tmp;
        cin >> tmp;
        X1.push_back(tmp);
        X2.push_back(tmp);
    }
    
    sort(X2.begin(), X2.end());
    int numL = X2[N/2-1];
    int numR = X2[N/2];
    rep(i, 0, N){
        
        if(X1[i] <= numL){
            cout << numR << endl;
        } else {
             cout << numL << endl;
        }
    }
    
    return 0;
}
