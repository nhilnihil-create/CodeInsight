#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
 
using namespace std;

int main(){
    int N;
    cin >> N;

    double sum = 0;

    for(int i = 0; i < N; i++){
        double x;
        string u;

        cin >> x >> u;

        if(u[0] == 'J'){
            sum += x;
        }else{
            sum += 380000*x;
        }
    }

    cout << to_string(sum) << endl;

    return 0;
}