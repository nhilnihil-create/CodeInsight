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
    long long N;
    cin >> N;
    for(long long h=1; h<=3500; h++){
        for(long long n=1; n<=3500; n++){
            if(4*h*n-(h+n)*N<=0)continue;
            if(N*h*n%(4*h*n-(h+n)*N)==0){
                cout << h << ' ' << n << ' ' << N*h*n/(4*h*n-(h+n)*N) << endl;
                return 0;
            }
        }
    }
}