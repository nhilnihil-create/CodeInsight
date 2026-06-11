#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N,K;
    cin >> N >>K;
    vector<int>A(N);
    rep(i, 0, N){
        cin >> A[i];
    }
    N--;
    K--;
    if(N%K == 0){
      cout<<(N/K)<<endl;
    }else{
      cout<<(1+N/K)<<endl;
    }
    
    
    return 0;
}
