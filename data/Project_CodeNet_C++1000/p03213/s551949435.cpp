#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

//n以下の素数列
void LF_Prime_Sequence(const long &n, vector<long> &viPrime){
    if(n < 2){
        return;
    }
    viPrime.clear();
    vector<char> aiType(n + 1,0);
    for (long i = 2; i * i <= n; i++){
        for(long j = 2; j * i <= n; j++){
            aiType[j * i] = 1;
        }
    }
    for (long i = 2; i <= n; i++){
        if(aiType[i] == 0){
            viPrime.push_back(i);
        }
    }
    return;
}

int main(){
    long n;
    scanf("%ld", &n);
    vector<long> viPrime;
    LF_Prime_Sequence(n/2, viPrime);
    long nCountTwo=0,nCountFour=0,nCountFourteen=0,nCountTwentyfour=0,nCountSeventyfour=0;
    for(int i=0; i<viPrime.size();i++){
        
        long k = viPrime[i];
        long nCountk = 0;
        long nTmp = n;
        while(nTmp >= k){
            nTmp /= k;
            nCountk += nTmp;
        }
        if(nCountk >= 2){
            nCountTwo++;
        }
        if(nCountk >= 4){
            nCountFour++;
        }
        if(nCountk >= 14){
            nCountFourteen++;
        }
        if(nCountk >= 24){
            nCountTwentyfour++;
        }
        if(nCountk >= 74){
            nCountSeventyfour++;
        }
    }
    long nAns = 0;
    nAns += nCountSeventyfour;
    nAns += nCountTwentyfour * (nCountTwo - 1);
    nAns += nCountFourteen * (nCountFour - 1);
    nAns += nCountFour * (nCountFour - 1) * (nCountTwo - 2) / 2;
  
    printf("%ld\n", nAns);
    return 0;
}
