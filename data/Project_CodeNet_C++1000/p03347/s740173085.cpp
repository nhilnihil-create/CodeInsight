#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,0);
    long long ans=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    if(A[0]!=0){
        cout << -1 << endl;
        return 0;
    }
    for(int i=N-1; i>=0; i--){
        cin >> A[i];
        if(A[i]<A[i+1]-1){
            cout << -1 << endl;
            return 0;
        }
        if(A[i]==A[i-1]+1){
            ans++;
        }else if(A[i]<=i){
            ans+=A[i];
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}