#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    int N;
    cin >> N;

    int isEight=0;

    for(int x=3; x<=N; x+=2){
        int cnt = 2;
        for(int i=3; i<x; i+=2){
            if( 0 == (x%i) ){
                cnt = cnt + 1;
            }
            else{
                /* nothing */
            }
        }
        if(8 == cnt){
            isEight = isEight + 1;
        }
    }

    cout << isEight << endl;

}