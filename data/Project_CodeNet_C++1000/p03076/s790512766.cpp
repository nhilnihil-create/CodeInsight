#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int time = 0;
    int vals[5] = {A, B, C, D, E};

    int last_index = 0;
    int r = 0;
    for(int i=0; i<5; i++){
        int tmp_r = vals[i] % 10;
        if(tmp_r != 0){
            if(r < 10-tmp_r){
                r = 10 - tmp_r;
                last_index = i;
            }
        }
    }

    for(int i=0; i<5; i++){
        if(i!=last_index){
            time += (int)ceil(vals[i]/10.0)*10;
        } else {
            time += vals[i];
        }
    }
    cout << time << endl;
    return 0;
}