#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    std::vector< int > tmp;
    for(int i=1; i<=(int)std::sqrt(A[0]); i++){
        if(A[0] % i == 0){
            tmp.push_back(i);
            if(i * i != A[0]){
                tmp.push_back(A[0] / i);
            }
        }
    }
    for(int i=1; i<=(int)std::sqrt(A[1]); i++){
        if(A[1] % i == 0){
            tmp.push_back(i);
            if(i * i != A[1]){
                tmp.push_back(A[1] / i);
            }
        }
    }
    
    std::sort(tmp.begin(), tmp.end());
    std::vector< int > GCD(1, tmp[0]);
    std::vector< int > GCD_cnt(1, 1);
    
    for(int i=1; i<(int)tmp.size(); i++){
        if(tmp[i] == tmp[i-1]){
            GCD_cnt[GCD_cnt.size() - 1]++;
        }else{
            GCD.push_back(tmp[i]);
            GCD_cnt.push_back(1);
        }
    }
    
    for(int i=2; i<N; i++){
        std::vector< int > GCD_tmp;
        std::vector< int > GCD_cnt_tmp;
        for(int j=0; j<GCD.size(); j++){
            if(A[i] % GCD[j] == 0){
                GCD_tmp.push_back(GCD[j]);
                GCD_cnt_tmp.push_back(GCD_cnt[j]+1);
            }else if(GCD_cnt[j] == i){
                GCD_tmp.push_back(GCD[j]);
                GCD_cnt_tmp.push_back(GCD_cnt[j]);
            }
        }
        GCD = GCD_tmp;
        GCD_cnt = GCD_cnt_tmp;
    }
    
    std::cout << GCD[GCD.size() - 1] << std::endl;
    
    return 0;
}

