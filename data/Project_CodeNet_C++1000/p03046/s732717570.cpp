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
    int M, K;
    cin >> M >> K;
    if(M==1){
        if(K==0){
            cout << "1 1 0 0" << endl;
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(K < (1<<M)){
        for(int i=0; i<(1<<M); i++){
            if(i==K)continue;
            cout << i << ' ';
        }
        cout << K << ' ';
        for(int i=(1<<M)-1; i>=0; i--){
            if(i==K)continue;
            cout << i << ' ';
        }
        cout << K << endl;
    }else{
        cout << -1 << endl;
    }
}