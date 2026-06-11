#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>
#include <stdlib.h>
# include <map>

using namespace std;

int main(){
    int s,cnt;
    map<int ,bool> m;
    cin >> s;
    bool flag = true;
    cnt = 1;
    m[s] = true;
    while(flag){
        if (s%2 == 0){
            s = s/2;
            if(m.find(s) != m.end()){
                flag = false;
            }
        }
        else{
            s = 3*s + 1;
            if(m.find(s) != m.end()){
                flag = false;
            }
        }
        cnt += 1;
        m[s] = true;
    }
    cout << cnt << endl;
}
