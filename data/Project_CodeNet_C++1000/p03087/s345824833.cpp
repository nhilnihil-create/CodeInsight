#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>
int main(void){
    long N,Q;
    std::cin >> N >> Q;
    std::string S;
    std::cin >> S;
    long Alist[100000+1]={};
    long Clist[100000+1]={};

    long ACsum=0;
    Alist[0]=0;
    Clist[0]=0;
    Clist[1]=0;
    for(long i=0; i<S.length()-1;i++){
        if(S[i]=='A' && S[i+1]=='C'){
            ACsum++;
        }
        Alist[i+1]=ACsum;
        Clist[(i+1)+1]=ACsum;
    }
    Alist[S.length()]=ACsum;

    for(long i=0; i<Q; i++){
        long l,r;
        std::cin >> l >> r;
        std::cout << std::min(Alist[r]-Alist[l-1],Clist[r]-Clist[l]) << std::endl;;
    }
    return 0;
}