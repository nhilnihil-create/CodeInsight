#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main(void){
    
    int N, X;
    cin >> N >> X;
    
    int min_gram = INT_MAX;
    for(int i = 0; i < N; i++){
        int m;
        cin >> m;
        min_gram = min(min_gram, m);
        X -= m;
    }
    
    int ans = N + (X / min_gram);
    
    cout << ans << endl;

}
