#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n,m;
    scanf("%ld %ld", &n, &m);
    vector<long> vvippp(n);
    vector<long> vvipmp(n);
    vector<long> vvimpp(n);
    vector<long> vvimmp(n);
    for(long i = 0; i < n; i++){
        long x,y,z;
        scanf("%ld %ld %ld", &x, &y, &z);
        vvippp[i] = x + y + z;
        vvipmp[i] = x - y + z;
        vvimpp[i] = -x + y + z;
        vvimmp[i] = -x - y + z;        
    }
    
    sort(vvippp.begin(), vvippp.end());
    sort(vvipmp.begin(), vvipmp.end());
    sort(vvimpp.begin(), vvimpp.end());
    sort(vvimmp.begin(), vvimmp.end());
  
    long nAns = 0;
    long iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvippp[i];
    }
    nAns = max(nAns, -iSum);
    iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvippp[n - 1 - i];
    }
    nAns = max(nAns, iSum);
    iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvipmp[i];
    }
    nAns = max(nAns, -iSum);
    iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvipmp[n - 1 - i];
    }
    nAns = max(nAns, iSum);
    iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvimpp[i];
    }
    nAns = max(nAns, -iSum);
    iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvimpp[n - 1 - i];
    }
    nAns = max(nAns, iSum);
    iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvimmp[i];
    }
    nAns = max(nAns, -iSum);
    iSum = 0;
    for(long i = 0; i < m; i++){
        iSum += vvimmp[n - 1 - i];
    }
    nAns = max(nAns, iSum);
    iSum = 0;
  
    printf("%ld", nAns);
    return 0;
}
