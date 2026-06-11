#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 8000;
bool dpx[2][2*MAX];
bool dpy[2][2*MAX];

int main(){
    string op; cin >> op;
    int gx,gy; cin >> gx >> gy;

    const int N = op.size();

    vector<vector<int> > disp(2);
    int d=0;
    for(int i=0;i<N;i++){
        int count = 0;
        while(op[i] == 'F' && i < N){
            count++;
            i++;
        }
        disp[d].push_back(count);
        d = 1-d;
    }
    const int start = 8000; //原点を(8000,8000)と考える
    dpx[0][start] = true;
    dpy[0][start] = true;
    for(int i=0;i<disp[0].size();i++){
        for(int j=0;j<2*MAX;j++){
            if(dpx[i%2][j]){
                dpx[(i+1)%2][j+disp[0][i]] = true;
                if(i>0){
                    dpx[(i+1)%2][j-disp[0][i]] = true;
                }
            }
            dpx[i%2][j] = false;
        }
    }
    for(int i=0;i<disp[1].size();i++){
        for(int j=0;j<2*MAX;j++){
            if(dpy[i%2][j]){
                dpy[(i+1)%2][j+disp[1][i]] = true;
                dpy[(i+1)%2][j-disp[1][i]] = true;
                dpy[i%2][j] = false;
            }
        }
    }

    if(dpx[(disp[0].size())%2][gx + start] && dpy[(disp[1].size())%2][gy + start]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}