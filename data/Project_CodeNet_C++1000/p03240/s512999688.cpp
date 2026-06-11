#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    for(int i = 0; i < N; i++){
        cin >> x.at(i) >> y.at(i) >> h.at(i);
    }
    for(int Cx = 0; Cx <= 100; Cx++){
        bool check1 = false;
        for(int Cy = 0; Cy <= 100; Cy++){
            int H;
            for(int i = 0; i < N; i++){
                if(h.at(i) != 0){
                    H = abs(x.at(i) - Cx) + abs(y.at(i) - Cy) + h.at(i);
                    break;
                }
            }
            bool check2 = true;
            for(int i = 0; i < N; i++){
                if(max(H - abs(x.at(i) - Cx) - abs(y.at(i) - Cy), 0) != h.at(i)){
                    check2 = false;
                    break;
                }
            }
            if(check2){
                cout << Cx << " " << Cy << " " << H << endl;
                check1 = true;
                break;
            }
        }
        if(check1){
            break;
        }
    }
    return 0;
}