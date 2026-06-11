#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> vviEdge(n + 1);
    for (int i = 0; i < n-1; i++){
        int a,b;
        int nLength;
        scanf("%d %d %d", &a, &b, &nLength);
        if(nLength % 2 == 0){
            vviEdge[a].push_back(b);
            vviEdge[b].push_back(a);
        }
        else {
            vviEdge[a].push_back(b+n);
            vviEdge[b].push_back(a+n);
        }
    }
  
    vector<char> viColor(n + 1, -1);
    viColor[1] = 1;
    queue<int> qiSearchNum;
    qiSearchNum.push(1);
    while(!qiSearchNum.empty()){
        int i = qiSearchNum.front();
        qiSearchNum.pop();
        for(int j = 0; j < vviEdge[i].size(); j++){
            if(vviEdge[i][j] <= n){
                if(viColor[vviEdge[i][j]] == -1){
                    viColor[vviEdge[i][j]] = viColor[i];
                    qiSearchNum.push(vviEdge[i][j]);
                }
            }
            else {
                if(viColor[vviEdge[i][j]-n] == -1){
                    viColor[vviEdge[i][j]-n] = 1 - viColor[i];
                    qiSearchNum.push(vviEdge[i][j]-n);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d\n", viColor[i]);
    }
    return 0;
}
