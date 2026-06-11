#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
int N;
int ko =0;
int roop = 3;
string a[3] = {"3","5","7"};
void dfs(string A){
    if (A.size() == roop) {
        if(A.find("3") != -1&&A.find("5") != -1&&A.find("7")!=-1){
           int num = atoi(A.c_str());
           if(num <= N)ko += 1;
        }
        return;
    }

    for (int v = 0; v < 3; ++v) {
        A += a[v];
        dfs(A);
        A.erase( --A.end() );
    }
}

int main() {
    cin>>N;
    string A;
    for(int i = 0;i<10;i++){
      dfs(A);
      roop += 1;
      if(roop == 10)break;
    }
    cout<<ko;
    return 0;
}