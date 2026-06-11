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

int log3(int N){
    int ret=0;
    while(N>=3){
        N/=3;
        ret++;
    }
    return ret;
}

void cout_vec(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int L;
    cin >> L;
    int goal=L;
    L--;

    int num=13;
    vector<int> pow3(21,1);
    for(int i=0; i<num; i++){
        pow3[i+1]=pow3[i]*3;
    }

    int n=log3(L+1);
    vector<vector<int> > path(0);
    for(int i=1; i<num; i++){
        path.push_back({i, i+1, 0});
    }

    int base=1;
    for(int i=0; i<n; i++){
        for(int j=1; j<3; j++){
            path.push_back({i+1, i+2, j*base});
        }
        base*=3;
    }

    L-=base;
    while(base!=goal){
        n=log3(L+1);
        path.push_back({n+1,num,base});
        base+=pow3[n];
        L-=pow3[n];
    }

    cout << num << ' ' << (int)path.size() << endl;
    for(auto &p:path){
        cout_vec(p);
    }
}