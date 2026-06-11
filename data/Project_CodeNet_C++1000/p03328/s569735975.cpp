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
    int a,b;

    cin >> a >> b;

    int sum = 1;
    int i = 2;

    while(1){
        int l = sum;
        int r = sum+i;

        int j = 1;

        while(1){
            if(a + j == l && b + j == r){
                cout << j << endl;
                return 0;
            }
            
            if(a + j > l || b + j> r){
                break;
            }

            j++;
        }

        sum += i;
        i++;
    }
 
    return 0;
}