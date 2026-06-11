#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
#include <queue>

using ll =  long long;
#define rep(i,n) for(int i= 0; i< (n); i++)
using namespace std;
using Graph = vector<vector<int>>;

int main(){

    int a, b, k;
    cin >> a >> b >> k;
    int cnt=0;
    for(int i=100; i>=1; i--){
        if(a%i==0 && b%i==0){
             cnt++;
            if(cnt==k){
                cout << i << endl;
                return 0;
            }
        }
    }
    
}