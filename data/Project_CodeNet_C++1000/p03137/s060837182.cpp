#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    if(n >= m){
        printf("%d", 0);
        return 0;
    }
    vector<int> viCoordinate(m);
    for(int i = 0; i < m; i++){
        scanf("%d", &viCoordinate[i]);
    }
    sort(viCoordinate.begin(), viCoordinate.end());

    int nAns = viCoordinate[m-1] - viCoordinate[0];
    vector<int> viDist;
    for(int i = 0; i < m-1; i++){
        int iDist = viCoordinate[i+1] - viCoordinate[i];
        viDist.push_back(iDist);
    }
    sort(viDist.begin(), viDist.end());
    
    for(int i = m-2; i > m-n-1; i--){
        nAns -= viDist[i];
    }
  
    printf("%d", nAns);
    return 0;
}
