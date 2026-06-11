#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    long n;
    scanf("%ld", &n);
    vector<long> viCount(n,0);
    vector<pair<long, long> > viiEdge;
    for(long i = 0; i < n-1; i++){
        long a,b;
        scanf("%ld %ld", &a, &b);
        a--;
        b--;
        viCount[a]++;
        viCount[b]++;
        viiEdge.push_back(make_pair(a, b));
    }
    
    vector<long> viNum(n);
    for(long i = 0; i < n; i++){
        scanf("%ld", &viNum[i]);
    }
    sort(viNum.begin(), viNum.end());
    long nSum = 0;
    for(long i = 0; i < n-1; i++){
        nSum += viNum[i];
    }
    printf("%ld\n", nSum);    
  
    long k = 0;
    vector<long> viAns(n);
    while(k < n - 1){
        for(long i = 0; i < n; i++){
            if(viCount[i] == 1){
                viAns[i] = viNum[k];
                k++;
                if(k == n - 1){
                    break;
                }
                viCount[i]--;
                long j;
                long iPair;
                for(j = 0; j < viiEdge.size(); j++){                    
                    if(viiEdge[j].first == i){
                        iPair = viiEdge[j].second;
                        viiEdge.erase(viiEdge.begin() + j);
                        break;
                    }
                    if(viiEdge[j].second == i){
                        iPair = viiEdge[j].first;
                        viiEdge.erase(viiEdge.begin() + j);
                        break;
                    }
                }
                viCount[iPair]--;
            }
        }
    }
    for(long i = 0; i < n; i++){
        if(viAns[i] == 0){
            viAns[i] = viNum[n-1];
        }
        printf("%ld ", viAns[i]);
    }
    return 0;
}
