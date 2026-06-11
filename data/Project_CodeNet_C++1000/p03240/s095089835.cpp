#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int xyh[n][3];
    for(int i = 0; i < n; i++)
        cin >> xyh[i][0] >> xyh[i][1] >> xyh[i][2];
    for(int cx = 0; cx <= 100; cx++){
        for(int cy = 0; cy <= 100; cy++){
            int h = -1;
            bool succ = true;
            for(int i = 0; i < n; i++)
                if(xyh[i][2] != 0){
                    if(h == -1)
                        h = abs(xyh[i][0]-cx) + abs(xyh[i][1]-cy) + xyh[i][2];
                    else if(abs(xyh[i][0]-cx) + abs(xyh[i][1]-cy) + xyh[i][2] != h){
                        succ = false;
                        break;
                    }
                }
            if(succ){
                for(int i = 0; i < n; i++)
                    if(xyh[i][2] == 0 && h - abs(xyh[i][0]-cx) - abs(xyh[i][1]-cy) > 0){
                        succ = false; 
                        break;
                    }
                if(succ){
                    cout << cx << " " << cy << " " << h << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
